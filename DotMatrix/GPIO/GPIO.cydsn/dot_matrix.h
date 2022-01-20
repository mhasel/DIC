// dot_matrix.h, Michael Haselberger

// header/include guard
// #pragma once might work also - not sure for gcc-arm-none-eabi compiler
#if !defined(__DOT_MATRIX__)
#define __DOT_MATRIX__
    
//#define glue1name name
//#define glue1helper (index) glue1name##index
//#define glue1(index) glue1helper(index)
//
//void name1(void);
//glue1(1)();
 
// Helper macros to allow abstracting of name specific PinXY_write functions   
// --------!! These need to be updated if the pin names change !! -------
// Default: PinColX_Write and PinRowX_Write, where X is the index (e.g. PinCol8_Write)
#define COL_HELPER(__INDEX__) Pin_Col##__INDEX__##_Write    
#define ROW_HELPER(__INDEX__) Pin_Row##__INDEX__##_Write
#define COL(__INDEX__) COL_HELPER(__INDEX__)
#define ROW(__INDEX__) ROW_HELPER(__INDEX__)    
    
#include <stdint.h>
        
typedef enum level
{
    LOW = 0,
    HIGH = 0xFF
} level;  

// LED pattern function prototypes
void reset_matrix(void);
void sweep_horizontal(void);  
void sweep_vertical(void);
void draw_squares(void);

// function pointer for pin_write function
typedef void (*pin_write)(level lvl);

// struct containing a function pointer for each LED in the 8x8 matrix
// use __attribute__((packed)) if struct padding/memory is a concern (might affect performance)
typedef struct dot_matrix
{
    pin_write col[8];    
    pin_write row[8];
} dot_matrix;


#endif // __DOT_MATRIX__