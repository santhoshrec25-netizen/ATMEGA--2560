#include "buzzer.h"
#include "buzzer_reg.h"
#include "gpio.h"

void buzzer_init(void)
{
    pinmode(BUZZER_PORT, BUZZER_PIN, OUTPUT);
    buzzer_off();
}

void buzzer_on(void)
{
    gpio_write(BUZZER_PORT, BUZZER_PIN, HIGH);
}

void buzzer_off(void)
{
    gpio_write(BUZZER_PORT, BUZZER_PIN, LOW);
}