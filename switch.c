#include "switch.h"


/*==================================================
                  SWITCH DRIVER
==================================================*/

void switch_init(uint8_t portnum, uint8_t pinnum)
{
    pinmode(portnum, pinnum, INPUT);
}


uint8_t switch_read(uint8_t portnum, uint8_t pinnum)
{
    return gpio_read(portnum, pinnum);
}


uint8_t switch_is_pressed(uint8_t portnum, uint8_t pinnum)
{
    if(gpio_read(portnum, pinnum) == HIGH)
    {
        return 1;
    }

    return 0;
}