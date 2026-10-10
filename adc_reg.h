#ifndef ADC_REG_H
#define ADC_REG_H

#include <stdint.h>

/* ADC Registers */

#define ADMUX  (*(volatile uint8_t*)0x7C)
#define ADCSRA (*(volatile uint8_t*)0x7A)
#define ADCL   (*(volatile uint8_t*)0x78)
#define ADCH   (*(volatile uint8_t*)0x79)

/* ADC Control and Status Register A */

#define ADPS0 0
#define ADPS1 1
#define ADPS2 2

#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

/* ADC Multiplexer */

#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3

#define ADLAR 5

#endif