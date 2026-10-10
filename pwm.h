#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void pwm_init(uint8_t portnum, uint8_t pinnum);

void pwm_set_duty(uint8_t duty);

void pwm_start(void);

void pwm_stop(void);

#ifdef __cplusplus
}
#endif

#endif