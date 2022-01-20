/* ========================================
 * Helligkeitsmessung mit einfacher LED in Sperrrichtung
 * über Entladezeit der Sperrschichtkapazität
 * ========================================
*/
#include "project.h"
#include <stdio.h>

void Init();
uint16_t MeasureBrightness();
void UART_PutWord(uint16_t word);

int main(void)
{
    Init();
    
    for(;;)
    {
        uint16_t measurement = MeasureBrightness();        
        UART_PutWord(measurement);        
        CyDelay(1000);
    }
}

void Init()
{
    UART_Start();    
}

uint16_t MeasureBrightness()
{
    uint16_t ticks;
    volatile uint8_t pinState = 1;
    
    // drive pin high to charge capacitance
    Sensor_Pin_SetDriveMode(Sensor_Pin_DM_OD_HI);
    Sensor_Pin_Write(1);    
    // set pin to hiZ tri-state 
    Sensor_Pin_SetDriveMode(Sensor_Pin_DM_DIG_HIZ);
    
    for(ticks = 0; (pinState && ( ticks < UINT16_MAX )); ticks++)
    {        
        pinState = Sensor_Pin_Read();
        CyDelayUs(1);
    }
    
//    Sensor_Pin_SetDriveMode(Sensor_Pin_DM_OD_LO);          
    return ticks;
}


void UART_PutWord(uint16_t word)
{
    // sync
    UART_PutChar('M');
    // highByte
    UART_PutChar(word >> 8);
    // lowByte
    UART_PutChar(word & 0xFF);
}

/* [] END OF FILE */
