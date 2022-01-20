#include <stdint.h>
#include <stdio.h>

const uint8_t LOW_ = 0x00U;
const uint8_t HIGH_ = 0xFFU;

#define _LOW 0x00
#define _HIGH 0xFF

typedef enum level
{
    LOW = 0x0U,
    HIGH = 0xFFU
} level; 

void main(void)
{
    printf("enum:\n");
    printf("low: %d\n", LOW);
    printf("high: %d\n", HIGH);
    uint8_t inverted = ~LOW;
    printf("low inverted separate variable: %d\n", inverted);
    inverted = ~HIGH;
    printf("high inverted separate variable: %d\n", inverted);
    printf("inverted low cast: %d\n", (uint8_t)~LOW);
    printf("inverted low cast: %d\n", (uint8_t)~HIGH);

    printf("\n");     
    printf("const uint8_t:\n");
    printf("low: %d\n", LOW_);
    printf("high: %d\n", HIGH_);
    printf("low inverted: %d\n", (uint8_t)~LOW_);
    printf("high inverted: %d\n", (uint8_t)~HIGH_);

    printf("\n");    
    printf("defines:\n");
    printf("low: %d\n", LOW_);
    printf("high: %d\n", HIGH_);
    printf("low inverted: %d\n", (uint8_t)~_LOW);
    printf("high inverted: %d\n", (uint8_t)~_HIGH);

    printf("\n");    
    printf("Bitwise modulo for exponents of 2:\n");
    printf("modulo 8: %d, bitwise &7: %d\n", 12%8, 12&7);
}