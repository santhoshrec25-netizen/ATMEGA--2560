#include "sevenseg.h"

void sevenseg_init(uint8_t portnum)
{
    pinmode(portnum, SEG_A, OUTPUT);
    pinmode(portnum, SEG_B, OUTPUT);
    pinmode(portnum, SEG_C, OUTPUT);
    pinmode(portnum, SEG_D, OUTPUT);
    pinmode(portnum, SEG_E, OUTPUT);
    pinmode(portnum, SEG_F, OUTPUT);
    pinmode(portnum, SEG_G, OUTPUT);

    sevenseg_off(portnum);
}

void sevenseg_off(uint8_t portnum)
{
    gpio_write(portnum, SEG_A, LOW);
    gpio_write(portnum, SEG_B, LOW);
    gpio_write(portnum, SEG_C, LOW);
    gpio_write(portnum, SEG_D, LOW);
    gpio_write(portnum, SEG_E, LOW);
    gpio_write(portnum, SEG_F, LOW);
    gpio_write(portnum, SEG_G, LOW);
}

void sevenseg_display(uint8_t portnum, uint8_t digit)
{
    switch(digit)
    {
        case 0:
            gpio_write(portnum, SEG_A, HIGH);
            gpio_write(portnum, SEG_B, HIGH);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, HIGH);
            gpio_write(portnum, SEG_E, HIGH);
            gpio_write(portnum, SEG_F, HIGH);
            gpio_write(portnum, SEG_G, LOW);
            break;

        case 1:
            gpio_write(portnum, SEG_A, LOW);
            gpio_write(portnum, SEG_B, HIGH);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, LOW);
            gpio_write(portnum, SEG_E, LOW);
            gpio_write(portnum, SEG_F, LOW);
            gpio_write(portnum, SEG_G, LOW);
            break;

        case 2:
            gpio_write(portnum, SEG_A, HIGH);
            gpio_write(portnum, SEG_B, HIGH);
            gpio_write(portnum, SEG_C, LOW);
            gpio_write(portnum, SEG_D, HIGH);
            gpio_write(portnum, SEG_E, HIGH);
            gpio_write(portnum, SEG_F, LOW);
            gpio_write(portnum, SEG_G, HIGH);
            break;

        case 3:
            gpio_write(portnum, SEG_A, HIGH);
            gpio_write(portnum, SEG_B, HIGH);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, HIGH);
            gpio_write(portnum, SEG_E, LOW);
            gpio_write(portnum, SEG_F, LOW);
            gpio_write(portnum, SEG_G, HIGH);
            break;

        case 4:
            gpio_write(portnum, SEG_A, LOW);
            gpio_write(portnum, SEG_B, HIGH);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, LOW);
            gpio_write(portnum, SEG_E, LOW);
            gpio_write(portnum, SEG_F, HIGH);
            gpio_write(portnum, SEG_G, HIGH);
            break;

        case 5:
            gpio_write(portnum, SEG_A, HIGH);
            gpio_write(portnum, SEG_B, LOW);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, HIGH);
            gpio_write(portnum, SEG_E, LOW);
            gpio_write(portnum, SEG_F, HIGH);
            gpio_write(portnum, SEG_G, HIGH);
            break;

        case 6:
            gpio_write(portnum, SEG_A, HIGH);
            gpio_write(portnum, SEG_B, LOW);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, HIGH);
            gpio_write(portnum, SEG_E, HIGH);
            gpio_write(portnum, SEG_F, HIGH);
            gpio_write(portnum, SEG_G, HIGH);
            break;

        case 7:
            gpio_write(portnum, SEG_A, HIGH);
            gpio_write(portnum, SEG_B, HIGH);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, LOW);
            gpio_write(portnum, SEG_E, LOW);
            gpio_write(portnum, SEG_F, LOW);
            gpio_write(portnum, SEG_G, LOW);
            break;

        case 8:
            gpio_write(portnum, SEG_A, HIGH);
            gpio_write(portnum, SEG_B, HIGH);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, HIGH);
            gpio_write(portnum, SEG_E, HIGH);
            gpio_write(portnum, SEG_F, HIGH);
            gpio_write(portnum, SEG_G, HIGH);
            break;

        case 9:
            gpio_write(portnum, SEG_A, HIGH);
            gpio_write(portnum, SEG_B, HIGH);
            gpio_write(portnum, SEG_C, HIGH);
            gpio_write(portnum, SEG_D, HIGH);
            gpio_write(portnum, SEG_E, LOW);
            gpio_write(portnum, SEG_F, HIGH);
            gpio_write(portnum, SEG_G, HIGH);
            break;

        default:
            sevenseg_off(portnum);
            break;
    }
}