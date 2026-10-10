#include "pwm.h"
#include "gpio.h"
#include "timer.h"

static uint8_t pwm_port;
static uint8_t pwm_pin;
static uint8_t pwm_duty;
static uint8_t pwm_running;


void pwm_init(uint8_t portnum, uint8_t pinnum)
{
    pwm_port = portnum;
    pwm_pin = pinnum;

    pwm_duty = 0;
    pwm_running = 0;

    pinmode(pwm_port, pwm_pin, OUTPUT);

    gpio_write(pwm_port, pwm_pin, LOW);
}


void pwm_set_duty(uint8_t duty)
{
    pwm_duty = duty;
}


void pwm_start(void)
{
    pwm_running = 1;

    while(pwm_running)
    {
        /*
         * 1000 us = 1 ms PWM period
         *
         * Duty:
         * 0   = 0%
         * 64  = 25%
         * 128 = 50%
         * 192 = 75%
         * 255 = 100%
         */

        if(pwm_duty > 0)
        {
            gpio_write(pwm_port, pwm_pin, HIGH);

            timer_delay(
                ((uint32_t)pwm_duty * 1000UL) / 255UL,
                micro_sec
            );
        }


        if(pwm_duty < 255)
        {
            gpio_write(pwm_port, pwm_pin, LOW);

            timer_delay(
                ((uint32_t)(255 - pwm_duty) * 1000UL) / 255UL,
                micro_sec
            );
        }
    }
}


void pwm_stop(void)
{
    pwm_running = 0;

    gpio_write(pwm_port, pwm_pin, LOW);
}