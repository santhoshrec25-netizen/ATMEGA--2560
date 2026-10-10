#include "led.h"
#include "timer.h"


/* Single LED */

void led_init(uint8_t portnum, uint8_t pinnum)
{
    pinmode(portnum, pinnum, OUTPUT);
    led_off(portnum, pinnum);
}

void led_on(uint8_t portnum, uint8_t pinnum)
{
    gpio_write(portnum, pinnum, HIGH);
}

void led_off(uint8_t portnum, uint8_t pinnum)
{
    gpio_write(portnum, pinnum, LOW);
}

void led_toggle(uint8_t portnum, uint8_t pinnum)
{
    gpio_toggle(portnum, pinnum);
}


/* LED Array */

void led_array_init(uint8_t portnum)
{
    for(uint8_t pin = 0; pin < 8; pin++)
    {
        pinmode(portnum, pin, OUTPUT);
    }

    led_array_off(portnum);
}

void led_array_write(uint8_t portnum, uint8_t value)
{
    for(uint8_t pin = 0; pin < 8; pin++)
    {
        if(value & (1 << pin))
        {
            gpio_write(portnum, pin, HIGH);
        }
        else
        {
            gpio_write(portnum, pin, LOW);
        }
    }
}

void led_array_on(uint8_t portnum)
{
    led_array_write(portnum, 0xFF);
}

void led_array_off(uint8_t portnum)
{
    led_array_write(portnum, 0x00);
}


/* LED 0 -> LED 7 */

void led_array_forward(uint8_t portnum)
{
    for(uint8_t pin = 0; pin < 8; pin++)
    {
        led_array_write(portnum, (1 << pin));

        timer_delay(300, milli_sec);
    }
}


/* LED 7 -> LED 0 */

void led_array_backward(uint8_t portnum)
{
    for(int8_t pin = 7; pin >= 0; pin--)
    {
        led_array_write(portnum, (1 << pin));

        timer_delay(300, milli_sec);
    }
}