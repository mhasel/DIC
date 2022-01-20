// dot_matrix.c, Michael Haselberger
// Description: Implements functions for creating patterns on 8x8 dot matrix shield.

/*
    Default delay is implemented with the blocking CyDelay function. 
    For a timer/interrupt implementation, uncomment this line:
*/
//#define DELAY_TIMER_INTERRUPT

#if !defined(DELAY_TIMER_INTERRUPT)
#include <CyLib.h>
#endif

#include "dot_matrix.h"

// Delay time constant. Needs to be defined in main.c
extern const uint16_t DELAY;

// "import" pin_write functions
extern void COL(1)(level lvl);
extern void COL(2)(level lvl);
extern void COL(3)(level lvl);
extern void COL(4)(level lvl);
extern void COL(5)(level lvl);
extern void COL(6)(level lvl);
extern void COL(7)(level lvl);
extern void COL(8)(level lvl);
                          
extern void ROW(1)(level lvl);
extern void ROW(2)(level lvl);
extern void ROW(3)(level lvl);
extern void ROW(4)(level lvl);
extern void ROW(5)(level lvl);
extern void ROW(6)(level lvl);
extern void ROW(7)(level lvl);
extern void ROW(8)(level lvl);

// initialize matrix struct
static const dot_matrix matrix =  
{
    {
        COL(1),
        COL(2),
        COL(3),
        COL(4),
        COL(5),
        COL(6),
        COL(7),
        COL(8),
    },
    {
        ROW(1),
        ROW(2),
        ROW(3),
        ROW(4),
        ROW(5),
        ROW(6),
        ROW(7),
        ROW(8) 
    }
};

static const uint8_t shape_squares[64] = 
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 0, 0, 0, 0, 1, 0,
    0, 1, 0, 1, 1, 0, 1, 0,
    0, 1, 0, 1, 1, 0, 1, 0,
    0, 1, 0, 0, 0, 0, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
};

static void columns_set_state(level lvl)
{
    // Logic is inverted for column pins   
    uint8_t inverted = ~lvl;
    for (uint8_t i = 0; i < 8; ++i)
    {
        matrix.col[i](inverted);
    }
}

static void rows_set_state(level lvl)
{
    for (uint8_t i = 0; i < 8; ++i)
    {
        matrix.row[i](lvl);
    }
}

static void get_arr_coordinates(uint8_t index, uint8_t *x, uint8_t *y)
{
    // index = (row * width) + column
    // row = index / width => (n/8 == n>>3)
    // col = index % width => (n%8 == n&7)        
    
    *x = index & 7;    
    *y = index >> 3;
}

void reset_matrix(void)
{
    columns_set_state(LOW);
    rows_set_state(LOW);
}

void sweep_horizontal(void)
{     
    reset_matrix();
    // row pins high        
    rows_set_state(HIGH);
    
    for (uint8_t i = 0; i < 8; ++i)
    {
        // all cols HIGH ( all pins are high = all LEDS off)
        columns_set_state(HIGH);

        matrix.col[i](HIGH);
        
        #if !defined(DELAY_INTERRUPT_TIMER)
        // wait
        CyDelay(DELAY);
        #endif
    }
}

void sweep_vertical(void)
{
    // column pins low        
    columns_set_state(LOW);
    
    for (uint8_t i = 0; i < 8; ++i)
    {
        // all rows low ( all pins are low = all LEDS off)
        rows_set_state(LOW);
        matrix.row[i](HIGH);
        
        #if defined(DELAY_BLOCKING)
        // wait
        CyDelay(delay_ms);
        #endif
    }
}

void draw_squares(void)
{
    static uint8_t col = 0;
    static uint8_t row = 0;
    
    // reset LEDs
    columns_set_state(LOW);
    rows_set_state(LOW);
    
    for (int i = 0; i < 64; ++i)
    {
        // check shape LUT for required LED state
        if (shape_squares[i] == 1)
        {
            // get column and row from LED that needs to be set
            get_arr_coordinates(i, &col, &row);
            // set LED
            matrix.col[col](HIGH);
            matrix.row[row](HIGH);
        }
    } 
}



