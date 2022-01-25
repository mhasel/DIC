#include "project.h"
#include <stdio.h>

#define R3 10000

typedef enum phase
{
    REF = 0,
    RESULT
}phase;

volatile uint8_t trig = 0;
CY_ISR(pin_level_high)
{
    trig = 1;
}

void discharge(void);
void measure(enum phase p, uint32_t* dst);
void write_adc_val(void);
uint32_t calculate_resistance(uint32_t* vals);

int main(void)
{
    isr_p_sense_StartEx(pin_level_high);
    isr_p_sense_ClearPending();
    CyGlobalIntEnable; 
//    ADC_SAR_Start();
//    ADC_SAR_StartConvert();
    UART_Start();
    UART_PutString("Starting...");
    char res[100];
    
    for(;;)
    {      
        static uint32_t ticks[2] = {0};
        discharge();       
        measure(REF, ticks);    
        
        sprintf(res, "Ref: %u\n\r",ticks[REF]);
        UART_PutString(res);
        
        discharge();        
        measure(RESULT, ticks);
        
        sprintf(res, "Result: %u\n\r",ticks[RESULT]);
        UART_PutString(res);  
        CyDelay(100);
    }
}

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