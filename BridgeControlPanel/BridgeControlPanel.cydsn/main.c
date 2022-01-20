
#include "project.h"

int main(void)
{
    CyGlobalIntEnable;
    UART_Start();
    ADC_SAR_Start();
    ADC_SAR_StartConvert();
    
    for(;;)
    {
        if(ADC_SAR_IsEndConversion(ADC_SAR_WAIT_FOR_RESULT)!= 0) 
        {        
            int16 result = ADC_SAR_GetResult16();    
            // sync byte
            UART_PutChar('M');
            // high byte
            UART_PutChar(result>>8);
            // low byte
            UART_PutChar(result & 0xFF);
            CyDelay(250);
        }
    }
    // open drain drives high mode für led übung
    // Pin_SW_SetDriveMode(Pin_SW_DM_OD_HI);   
    // Pin_SW_SetDriveMode(Pin_SW_DM_DIG_HIZ); 
}

