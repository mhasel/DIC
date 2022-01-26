#pragma once
#include <stdint.h>

#define R3 10000

typedef enum
{
    DISCHARGE = 0,
    MEASURE_REF,
    MEASURE_TOTAL,
    TRIGGERED,
    CAPTURE,
    TIMEOUT,
    IDLE
}state_t;

typedef enum pin_state
{
    LOW = 0,
    HIGH
} pin_state_t;

enum time
{
    REF = 0,
    TOTAL
};

enum pins
{
    DRAIN,
    CHARGE_REF,
    CHARGE_TOTAL
};

typedef struct state_machine
{
    volatile state_t state;
    volatile pin_state_t pin_state;
    uint32_t time_ref;
    uint32_t time_total;
} state_machine;
