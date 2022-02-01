#include "project.h"
#include <string.h>
#include <stdio.h>

char buf[100];
char *buf_ptr = buf;
char time[8];

void simple_decode(void);
void get_time(void);
void get_data(void);

int main(void)
{    
    uint8_t sequence_cplt = 0;
    UART_pc_Start();
    UART_gps_Start();
    UART_pc_PutString("Ready to receive\r\n");
    CyGlobalIntEnable;

    for(;;)
    {
       uint8_t gps_data = UART_gps_GetChar();
       *buf_ptr = gps_data;  
       switch (gps_data)
       {
            // no data - do nothing
            case 0x00:
                break;
            // EMEA sequence start character
            case '$':
                buf_ptr = buf;          
                buf_ptr++;
                break;  
            // LF - signals end of sequence. terminate string with null
            case 0x0A:
                *(buf_ptr + 1) = '\0';
                sequence_cplt = 1;
            default:   
                buf_ptr++;
        }
    
        if (sequence_cplt)
        {        
            sequence_cplt = 0;
            buf_ptr = buf;
            simple_decode();
        }
    }
}

void simple_decode(void)
{
    char cmp[5];    
    memcpy(cmp, buf+1, 5);    
    if (!strcmp(cmp, "GPGGA"))
    {
        UART_pc_PutString(buf);
        UART_pc_PutString("\n\r");
        get_time();      
        get_data();
        UART_pc_PutString("\n\r");
    } 
}

void get_time(void)
{
    sprintf(time, "  %c%c:%c%c:%c%c", buf[7], buf[8], buf[9], buf[10], buf[11], buf[12]);    
    UART_pc_PutString("\t\tGPS time:\t");
    UART_pc_PutString(time);    
    UART_pc_PutString("\n\r");
}

void get_data(void)
{
    // start after the time position in the GPGGA string
    char *index = (buf + 12);
    // count amount of commas encountered in string
    
    char out[11];
    // latitude
    for (uint8_t comma_cnt = 0; comma_cnt < 1; index++)
    {
        if (*index == ',')
        {
            ++comma_cnt;
        }
    }
    
    memcpy(out+1, index, 9);
    out[0] = ' ';
    out[10] = '\0'; 
    
    if(strchr(out, ',') == NULL)
    {
        UART_pc_PutString("\t\tLatitude:\t");
        UART_pc_PutString(out);
        UART_pc_PutString("\r\n");
    }
    
    // longitude
    for (uint8_t comma_cnt = 0; comma_cnt < 2; index++)
    {
        if (*index == ',')
        {
            ++comma_cnt;
        }
    }
    
    memcpy(out, index, 10);
    out[10] = '\0';
    
    if(strchr(out, ',') == NULL)
    {
        UART_pc_PutString("\t\tLongitude:\t");
        UART_pc_PutString(out);
        UART_pc_PutString("\r\n");
    }
        
    // gps fix
    for (uint8_t comma_cnt = 0; comma_cnt < 2; index++)
    {
        if (*index == ',')
        {
            ++comma_cnt;
        }
    }
    
    if(isdigit(*index) && ((*index == 1) || (*index == 2)))
    {
        UART_pc_PutString("\t\t\t\t\tGPS fix!:");
        UART_pc_PutString("\r\n");
    }
    
    // nr of satellites
    for (uint8_t comma_cnt = 0; comma_cnt < 1; index++)
    {
        if (*index == ',')
        {
            ++comma_cnt;
        }
    }
    
    memcpy(out, index, 2);
    out[2] = '\0';
    
    if(isdigit(*index) && isdigit(*index+1))
    {
        UART_pc_PutString("\t\t#Satellites:\t\t");
        UART_pc_PutString(out);
        UART_pc_PutString("\r\n");
    }    
}

