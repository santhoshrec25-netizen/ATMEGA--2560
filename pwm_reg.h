#ifndef PWM_REG_H
#define PWM_REG_H

#include <stdint.h>

/* Timer0 registers */

#define TCCR0A  (*(volatile uint8_t*)0x44)
#define TCCR0B  (*(volatile uint8_t*)0x45)

#define TCNT0   (*(volatile uint8_t*)0x46)

#define OCR0A   (*(volatile uint8_t*)0x47)
#define OCR0B   (*(volatile uint8_t*)0x48)


/* Timer0 Waveform Generation Mode bits */

#define WGM00  0
#define WGM01  1
#define WGM02  3


/* Timer0 Compare Output Mode bits */

#define COM0A0  6
#define COM0A1  7

#define COM0B0  4
#define COM0B1  5


/* Timer0 Clock Select bits */

#define CS00  0
#define CS01  1
#define CS02  2

#endif