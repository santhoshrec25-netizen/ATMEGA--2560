#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif
// single led
void led_init(uint8_t portnum, uint8_t pinnum);
void led_on(uint8_t portnum, uint8_t pinnum);
void led_off(uint8_t portnum, uint8_t pinnum);
void led_toggle(uint8_t portnum, uint8_t pinnum);

// multi led 
void led_array_init(uint8_t portnum);
void led_array_write(uint8_t portnum, uint8_t value);
void led_array_on(uint8_t portnum);
void led_array_off(uint8_t portnum);
void led_array_forward(uint8_t portnum);
void led_array_backward(uint8_t portnum);

#ifdef __cplusplus
}
#endif

#endif