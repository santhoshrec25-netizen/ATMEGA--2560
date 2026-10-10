#ifndef ADC_H
#define ADC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void adc_init(void);

void adc_select_channel(uint8_t channel);

uint16_t adc_read(uint8_t channel);

#ifdef __cplusplus
}
#endif

#endif