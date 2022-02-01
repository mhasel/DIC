#include "pseudo_adc.h"


// static function prototypes
static void _discharge(void);
static void _measure(enum time);
static void _set_discharge_pin(enum pin_state);
static void _set_charge_ref_pin(enum pin_state);
static void _set_charge_total_pin(enum pin_state);
static void _read_sense_pin(void);
static uint32_t _calculate_r (void); 

// internal state machine. not exposed outside of this translation unit
struct _sm 
{
    volatile state_t *state;
    volatile pin_state_t *pin_state;
    uint32_t *time_ref;
    uint32_t *time_total;
    uint8_t _is_initialized;
    
    void (*discharge)(void);
    void (*measure)(enum time);
    void (*set_pin[3])(enum pin_state);    
    void (*read_sense_pin)(void);
    uint32_t (*calculate_r)(void); 
} _sm ;

// 
void init_pseudo_adc(state_machine *sm_handle)
{
    _sm.state = &sm_handle->state;
    _sm.pin_state = &sm_handle->pin_state;
    _sm.time_ref = &sm_handle->time_ref;
    _sm.time_total = &sm_handle->time_total;
    
    // these functions don't need to be exposed to the handle
    _sm.discharge = _discharge;
    _sm.measure = _measure;
    _sm.set_pin[CHARGE_REF] = _set_charge_ref_pin;
    _sm.set_pin[CHARGE_TOTAL] = _set_charge_total_pin;
    _sm.set_pin[DRAIN] = _set_discharge_pin;
    _sm.read_sense_pin = _read_sense_pin;
    _sm.calculate_r = _calculate_r;  
    
    _sm._is_initialized = 1;
}

uint8_t run_state_machine(void)
{
    if (!_sm._is_initialized)
    {
        return 255;
    }
         
    return 0;
}

static void _discharge(void)
{

}

static void _measure(enum time time)
{

}

static void _set_discharge_pin(enum pin_state pin_state)
{

}

static void _set_charge_ref_pin(enum pin_state pin_state)
{

}

static void _set_charge_total_pin(enum pin_state pin_state)
{

}

static void _read_sense_pin(void)
{

}

static uint32_t _calculate_r (void)
{

}