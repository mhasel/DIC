// main.c, Haselberger Michael
// Description: 8x8 dot matrix patterns, endlessly.
#include "project.h"
#include <stdint.h>
#include "dot_matrix.h"

// LEDs rate of change should be 2Hz -> delay 500ms each iteration
const uint16_t DELAY = 500U;

int main(void)
{
    CyGlobalIntEnable;
    reset_matrix();
        
    while(1)
    {
        sweep_horizontal();
        //sweep_vertical();
    }
}


