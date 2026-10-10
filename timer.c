#include "timer.h"
#include "timer_handle.h"
#include "timer_reg.h"

void timer_delay(uint32_t value, time_unit_t unit)
{
    uint32_t time_us;
    uint32_t total_ticks;
    uint32_t full_cycles;
    uint32_t remaining_ticks;

    // Convert requested time to microseconds
    time_us = time_to_microsec(value, unit);

    // Calculate total Timer0 ticks
    total_ticks =
        calculate_timer_ticks(time_us, prescaler_64);

    // 256 timer ticks per full cycle
    full_cycles = total_ticks / 256UL;

    remaining_ticks = total_ticks % 256UL;


    // Stop Timer0 before configuration
    tctrl0_b = 0;

    // CTC mode
    tctrl0_a = (1 << WGM01);

    // Full cycle = 256 timer ticks
    o_com_a = 255;

    // Reset counter
    tcount0 = 0;

    // Clear old compare flag
    t_int_flag_0 = (1 << OCF0A);

    // Start Timer0
    // Prescaler = 64
    tctrl0_b = (1 << CS01) | (1 << CS00);


    // Wait for complete cycles
    for(uint32_t i = 0; i < full_cycles; i++)
    {
        while(!(t_int_flag_0 & (1 << OCF0A)))
        {
        }

        // Clear compare flag
        t_int_flag_0 = (1 << OCF0A);
    }


    // Remaining ticks
    if(remaining_ticks > 0)
    {
        // Stop timer
        tctrl0_b = 0;

        // Set remaining count
        o_com_a = remaining_ticks - 1;

        // Reset counter
        tcount0 = 0;

        // Clear flag
        t_int_flag_0 = (1 << OCF0A);

        // Start timer
        tctrl0_b = (1 << CS01) | (1 << CS00);

        // Wait for remaining ticks
        while(!(t_int_flag_0 & (1 << OCF0A)))
        {
        }

        // Clear flag
        t_int_flag_0 = (1 << OCF0A);
    }


    // Stop timer
    tctrl0_b = 0;
}