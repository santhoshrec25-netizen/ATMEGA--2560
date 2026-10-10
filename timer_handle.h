#ifndef TIMER_HANDLE_H
#define TIMER_HANDLE_H

#include <stdint.h>
#include "timer_reg.h"

#ifdef __cplusplus
extern "C" {
#endif


//====================================================
// Timer Identification
//====================================================

typedef enum
{
    TIMER_ID_0,        // Timer 0
    TIMER_ID_1,        // Timer 1
    TIMER_ID_2,        // Timer 2
    TIMER_ID_3         // Timer 3

} timer_identify_t;


//====================================================
// Prescaler Options
//====================================================

typedef enum
{
    prescaler_1    = 1,
    prescaler_8    = 8,
    prescaler_64   = 64,
    prescaler_256  = 256,
    prescaler_1024 = 1024

} prescaler_t;


//====================================================
// Timer Type
//====================================================

typedef enum
{
    timer_blocking = 0,
    timer_non_blocking

} timer_type_t;


//====================================================
// Time Unit
//====================================================

typedef enum
{
    milli_sec = 0,
    micro_sec,
    sec

} time_unit_t;


//====================================================
// Timer Callback
//====================================================

typedef void (*timer_callback_t)(void);


//====================================================
// Timer Handle
//====================================================

typedef struct
{
    timer_identify_t timer;
    prescaler_t prescaler;
    timer_type_t type;
    timer_callback_t callback;

    uint32_t cycles;

    uint8_t partial_cycle8;
    uint16_t partial_cycle16;

    uint8_t ocr_value8;
    uint16_t ocr_value16;

} timer_handle_t;


//====================================================
// Function Declarations
//====================================================

// Convert time to microseconds
uint32_t time_to_microsec(uint32_t value,
                          time_unit_t unit);

// Calculate required timer ticks
uint32_t calculate_timer_ticks(uint32_t time_us,
                               prescaler_t prescaler);

// Configure blocking timer
void timer_block_handle_config(timer_handle_t *handle,
                               uint32_t time_us);

// Configure non-blocking timer
void timer_non_block_handle_config(timer_handle_t *handle,
                                   uint32_t time_us);

// Reset non-blocking timer
void timer_non_block_handle_reset(timer_handle_t *handle);


#ifdef __cplusplus
}
#endif

#endif