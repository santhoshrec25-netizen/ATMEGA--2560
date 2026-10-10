#ifndef BUZZER_H
#define BUZZER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);

#ifdef __cplusplus
}
#endif

#endif