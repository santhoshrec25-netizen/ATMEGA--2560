#include "ultrasonic.h"
#include "ultrasonic_reg.h"
#include "gpio.h"
#include <avr/io.h>
#include <util/delay.h>

#define TRIG_PORT portf
#define TRIG_PIN  0

#define ECHO_PORT portk
#define ECHO_PIN  0

void ultrasonic_init(uint8_t tp, uint8_t tpin,
                     uint8_t ep, uint8_t epin)
{
    (void)tp;
    (void)tpin;
    (void)ep;
    (void)epin;

    pinmode(TRIG_PORT, TRIG_PIN, OUTPUT);
    pinmode(ECHO_PORT, ECHO_PIN, INPUT);

    gpio_write(TRIG_PORT, TRIG_PIN, LOW);

    /* Timer1: normal mode, prescaler 8 */
    TCCR1A = 0;
    TCCR1B = 0;
}

uint16_t ultrasonic_read_cm(void)
{
    uint16_t ticks;

    /* Send trigger pulse */
    gpio_write(TRIG_PORT, TRIG_PIN, LOW);
    _delay_us(2);

    gpio_write(TRIG_PORT, TRIG_PIN, HIGH);
    _delay_us(10);
    gpio_write(TRIG_PORT, TRIG_PIN, LOW);

    /* Wait for ECHO to go HIGH, with timeout */
    TCCR1A = 0;
    TCCR1B = (1 << CS11);
    TCNT1 = 0;

    while(gpio_read(ECHO_PORT, ECHO_PIN) == LOW)
    {
        if(TCNT1 > 60000)
        {
            TCCR1B = 0;
            return 0;
        }
    }

    /* Start measuring the HIGH pulse */
    TCNT1 = 0;

    while(gpio_read(ECHO_PORT, ECHO_PIN) == HIGH)
    {
        if(TCNT1 > 60000)
        {
            TCCR1B = 0;
            return 0;
        }
    }

    ticks = TCNT1;
    TCCR1B = 0;

    /*
       16 MHz / 8 = 2 MHz
       One Timer1 tick = 0.5 us

       Distance in cm = pulse duration in us / 58
    */
    return (uint16_t)(ticks / 116);
}