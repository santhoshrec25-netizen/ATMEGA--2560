#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void ultrasonic_init(uint8_t trig_port, uint8_t trig_pin,
                     uint8_t echo_port, uint8_t echo_pin);

uint16_t ultrasonic_read_cm(void);

#ifdef __cplusplus
}
#endif

#endif