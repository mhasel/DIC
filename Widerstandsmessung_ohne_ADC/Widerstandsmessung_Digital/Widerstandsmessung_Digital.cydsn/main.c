#include "project.h"
#include <stdio.h>

#define R3 10000

typedef enum phase
{
    REF = 0,
    RESULT
}phase;

volatile uint8_t trig = 0;
CY_ISR(measurement_capture)
{
    trig = 1;
}
CY_ISR(measurement_timeout)
{
    trig = 2;
}

void init(void);
void discharge(void);
void measure(enum phase p, uint32_t* dst);
void write_adc_val(void);
uint32_t calculate_resistance(uint32_t* vals);

int main(void)
{
    init();
    char res[100];
    
    for(;;)
    {      
        static uint32_t time[2];
        static uint8_t state = 0;
        switch(state)
        {
            // discharge cap. also resets timer block
            case 0:
            case 2:
                discharge();
                Control_Reg_Write(0x01);
                ++state;
                break;
            case 1:
            case 3:
                // wait for trigger
                if (trig)
                {
                    // get capture value and write to memory
                    uint8_t i = (state == 1) ? REF : RESULT;
                    time[i] = Timer_ReadCapture();
                    trig = 0;
                    ++state;
                }
                break;
            case 4:
                sprintf(res, "Result: %u Ohm\n\r", calculate_resistance(time));
                UART_PutString(res);
                break;
                
        }
    }
}

void init()
{
    isr_p_sense_StartEx(measurement_capture);
    isr_timeout_StartEx(measurement_timeout);
    CyGlobalIntEnable; 
    Timer_Start();
    UART_Start();
    UART_PutString("Starting...");
//    ADC_SAR_Start();
//    ADC_SAR_StartConvert();
}

void discharge()
{
    P_discharge_Write(0);
    CyDelay(5);
    P_discharge_Write(1);
}

void measure(enum phase p, uint32_t* out)
{    
    volatile uint8_t pin_state = 0;
    uint32_t ticks;
    switch(p)
    {
        case REF:
            P_charge_ref_Write(1);
            for(ticks = 0; (!pin_state && ( ticks < UINT16_MAX )); ticks++)
            {        
                pin_state = P_sense_Read();
                CyDelayUs(1);
            }
            out[REF] = ticks;
            P_charge_ref_Write(0);
            break;
        case RESULT:
            P_charge_Write(1);
            for(ticks = 0; (!pin_state && ( ticks < UINT16_MAX )); ticks++)
            {        
                pin_state = P_sense_Read();
                CyDelayUs(1);
            }
            out[RESULT] = ticks;
            P_charge_Write(0);
            break;
    }
}

uint32_t calculate_resistance(uint32_t* ticks)
{
    return ((ticks[REF] * R3) / ticks[RESULT]) - R3;
}

// used to verify charge/discharge logic. obsolete.
void write_adc_val()
{
    static char adc_res[100];
    if(ADC_SAR_IsEndConversion(ADC_SAR_WAIT_FOR_RESULT)!= 0) 
    {        
        int16 result = ADC_SAR_GetResult16();    
        sprintf(adc_res, "ADC reading: %d\n\r", result);
        UART_PutString(adc_res);
    }
}