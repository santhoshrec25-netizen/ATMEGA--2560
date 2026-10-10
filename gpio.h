#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// GPIO register pointers declared in gpio.c
extern volatile uint8_t* ddr[11];
extern volatile uint8_t* port[11];
extern volatile uint8_t* pin_in[11];

// GPIO functions
void gpio_write(uint8_t portnum, uint8_t pinnum, uint8_t value);
void pinmode(uint8_t portnum, uint8_t pinnum, uint8_t mode);
uint8_t gpio_read(uint8_t portnum, uint8_t pinnum);
void gpio_toggle(uint8_t portnum, uint8_t pinnum);

#ifdef __cplusplus
}
#endif

// Port identifiers
#define porta  0
#define portb  1
#define portc  2
#define portd  3
#define porte  4
#define portf  5
#define portg  6
#define porth  7
#define portj  8
#define portk  9
#define portl  10

// GPIO logic levels and modes
#define HIGH   1
#define LOW    0
#define OUTPUT 1
#define INPUT  0

#endif