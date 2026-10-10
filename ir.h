#ifndef IR_H
#define IR_H

#include <stdint.h>
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

void ir_init(uint8_t portnum, uint8_t pinnum);
uint8_t ir_read(uint8_t portnum, uint8_t pinnum);
uint8_t ir_is_detected(uint8_t portnum, uint8_t pinnum);

#ifdef __cplusplus
}
#endif

#endif