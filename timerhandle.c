#include "timer_handle.h"

//====================================================
// Convert time to microseconds
//====================================================

uint32_t time_to_microsec(uint32_t value, time_unit_t unit)
{
    switch(unit)
    {
        case milli_sec:
            return value * 1000UL;

        case micro_sec:
            return value;

        case sec:
            return value * 1000000UL;

        default:
            return 0;
    }
}


//====================================================
// Calculate Timer Ticks
//====================================================

uint32_t calculate_timer_ticks(uint32_t time_us,
                               prescaler_t prescaler)
{
    uint32_t timer_frequency;

    timer_frequency = 16000000UL / prescaler;

    return ((uint64_t)time_us * timer_frequency) / 1000000ULL;
}


//====================================================
// Configure Blocking Timer
//====================================================

void timer_block_handle_config(timer_handle_t *handle,
                                uint32_t time_us)
{
    uint32_t total_ticks;

    total_ticks = calculate_timer_ticks(time_us,
                                        handle->prescaler);

    // Complete 256-count cycles
    handle->cycles = total_ticks / 256UL;

    // Remaining ticks
    handle->partial_cycle8 = total_ticks % 256UL;

    // Reset OCR
    handle->ocr_value8 = 0;

    // OCR counts from 0
    if(handle->partial_cycle8 > 0)
    {
        handle->ocr_value8 =
            handle->partial_cycle8 - 1;
    }
}


//====================================================
// Configure Non-Blocking Timer
//====================================================

void timer_non_block_handle_config(timer_handle_t *handle,
                                   uint32_t time_us)
{
    uint32_t total_ticks;

    total_ticks = calculate_timer_ticks(time_us,
                                        handle->prescaler);

    if(handle->timer == TIMER_ID_0 ||
       handle->timer == TIMER_ID_2)
    {
        // Timer 0 and Timer 2 are 8-bit

        handle->cycles =
            total_ticks / 256UL;

        handle->partial_cycle8 =
            total_ticks % 256UL;

        handle->ocr_value8 =
            handle->partial_cycle8;
    }
    else
    {
        // Timer 1 and Timer 3 are 16-bit

        handle->cycles =
            total_ticks / 65536UL;

        handle->partial_cycle16 =
            total_ticks % 65536UL;

        handle->ocr_value16 =
            handle->partial_cycle16;
    }
}


//====================================================
// Reset Non-Blocking Timer
//====================================================

void timer_non_block_handle_reset(timer_handle_t *handle)
{
    handle->cycles = 0;

    handle->partial_cycle8 = 0;
    handle->partial_cycle16 = 0;

    handle->ocr_value8 = 0;
    handle->ocr_value16 = 0;
}