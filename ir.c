#include "ir.h"
#include "ir_reg.h"

void ir_init(uint8_t portnum, uint8_t pinnum)
{
    pinmode(portnum, pinnum, INPUT);
}

uint8_t ir_read(uint8_t portnum, uint8_t pinnum)
{
    return gpio_read(portnum, pinnum);
}

uint8_t ir_is_detected(uint8_t portnum, uint8_t pinnum)
{
    if(ir_read(portnum, pinnum) == IR_ACTIVE_LOW)
        return 1;

    return 0;
}