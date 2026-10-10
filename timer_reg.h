#ifndef timer_reg_h//if not defined ATmega_2560_timer_reg_h
#define timer_reg_h//define ATmega_2560_timer_reg_h

#include <stdint.h>
#ifdef __cplusplus
extern "C"{
#endif

//===Timer 0 Registers===//

//control register
#define tctrl0_a   (*(volatile uint8_t*)0x44)//Timer/Counter Control Register A
#define tctrl0_b   (*(volatile uint8_t*)0x45)//Timer/Counter Control Register B

//counter register
#define tcount0     (*(volatile uint8_t*)0x46)//Timer/Counter Register

//output compare register
#define o_com_a    (*(volatile uint8_t*)0x47)// Output Compare Register A
#define o_com_b    (*(volatile uint8_t*)0x48)// Output Compare Register B
//interrupt register
#define t_int_flag_0    (*(volatile uint8_t*)0x35)//Timer Interrupt Flag Register
#define t_int_mask_0   (*(volatile uint8_t*)0x6E)//Timer Interrupt Mask Register


//=== Timer 0 Bit Definitions ===//

// ==Waveform Generation Mode(How it should operate depends on mode)==
#define WGM00    0//Waveform Generation Mode Bit 0
#define WGM01    1//Waveform Generation Mode Bit 1
#define WGM02    3//Waveform Generation Mode Bit 2

// ==Clock Select / Prescaler(Choose timer speed)==
#define CS00     0//Clock Select Bit 0
#define CS01     1//Clock Select Bit 1
#define CS02     2//Clock Select Bit 2

// ==Compare Output Mode==
#define COM0A0   6//Compare Output Mode Bit 0
#define COM0A1   7//Compare Output Mode Bit 1
#define COM0B0   4//Compare Output Mode Bit 0
#define COM0B1   5//Compare Output Mode Bit 1

// ==Timer Interrupt Mask==
#define TOIE0    0//Timer Overflow Interrupt Enable
#define OCIE0A   1//Output Compare A Interrupt Enable
#define OCIE0B   2//Output Compare B Interrupt Enable

// ==Timer Interrupt Flags==
#define TOV0     0//Timer Overflow Flag
#define OCF0A    1//Output Compare A Flag
#define OCF0B    2//Output Compare B Flag


#ifdef __cplusplus
}
#endif

#endif

