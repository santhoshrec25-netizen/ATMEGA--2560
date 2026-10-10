#ifndef timer_h
#define timer_h

#include <stdint.h>
#include "timer_handle.h"

#ifdef __cplusplus
extern "C"{
#endif  

//=== Timer Initialization===

// Initialize a timer with the required configuration
void timer_init(timer_handle_t *handle);



//===Blocking Timer===


// Generate a blocking delay
void timer_delay(uint32_t value, time_unit_t unit);



//===Non Blocking Timer===

// Start a non-blocking timer
void timer_start(timer_handle_t *handle);


// Stop a running timer
void timer_stop(timer_handle_t *handle);


// Deinitialize the timer
void timer_deinit(timer_handle_t *handle);

#ifdef __cplusplus
}
#endif

#endif