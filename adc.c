#include "adc.h"
#include "adc_reg.h"

void adc_init(void)
{
    /*
     * AVCC as reference
     * Right adjusted result
     */

    ADMUX = 0;


    /*
     * Enable ADC
     *
     * Prescaler = 128
     */

    ADCSRA = (1 << ADEN) |
             (1 << ADPS2) |
             (1 << ADPS1) |
             (1 << ADPS0);
}


void adc_select_channel(uint8_t channel)
{
    channel &= 0x07;

    ADMUX &= 0xF0;

    ADMUX |= channel;
}


uint16_t adc_read(uint8_t channel)
{
    uint16_t result;

    adc_select_channel(channel);

    /* Start conversion */

    ADCSRA |= (1 << ADSC);

    /* Wait for conversion */

    while(ADCSRA & (1 << ADSC))
    {
    }

    /* Read ADCL first, then ADCH */

    result = ADCL;

    result |= ((uint16_t)ADCH << 8);

    return result;
}