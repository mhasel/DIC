#include "project.h"

void tx_data(int32_t dword);

int main(void)
{   
    UART_Start();
    ADC_SAR_Start();
    ADC_SAR_StartConvert();  
    
    while(1)
    {          
        if(ADC_SAR_IsEndConversion(ADC_SAR_WAIT_FOR_RESULT)) 
        {
            int16_t data = ADC_SAR_GetResult16();   
            uint16_t pin_state = (VIN_Read()) ? 0x1388 : 0x0000;
            tx_data((data << 16) | pin_state);
        }
    }
}

void tx_data(int32_t dword)
{
    // sync
    UART_PutChar('M');
    
    // 0xADC ADC PIN PIN
    // ---- ADC data:
    // high byte
    UART_PutChar(dword >> 24);
    // low byte
    UART_PutChar((dword >> 16) & 0xFF);
    // ---- pin state:
    // high byte
    UART_PutChar((dword >> 8) & 0xFF);
    // low byte
    UART_PutChar(dword & 0xFF);
    CyDelayUs(1);
}