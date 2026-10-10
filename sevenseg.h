#ifndef SEVENSEG_H
#define SEVENSEG_H

#include <stdint.h>
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SEG_A 0
#define SEG_B 1
#define SEG_C 2
#define SEG_D 3
#define SEG_E 4
#define SEG_F 5
#define SEG_G 6

void sevenseg_init(uint8_t portnum);
void sevenseg_display(uint8_t portnum, uint8_t digit);
void sevenseg_off(uint8_t portnum);

#ifdef __cplusplus
}
#endif

#endif