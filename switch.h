#ifndef SWITCH_H
#define SWITCH_H

#include <stdint.h>
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

void switch_init(uint8_t portnum, uint8_t pinnum);

uint8_t switch_read(uint8_t portnum, uint8_t pinnum);

uint8_t switch_is_pressed(uint8_t portnum, uint8_t pinnum);

#ifdef __cplusplus
}
#endif

#endif