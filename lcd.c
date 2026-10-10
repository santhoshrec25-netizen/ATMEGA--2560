#include "lcd.h"
#include "lcd_reg.h"
#include "gpio.h"
#include <util/delay.h>

static void lcd_send_nibble(uint8_t data)
{
    gpio_write(LCD_D4_PORT, LCD_D4_PIN, (data >> 0) & 1);
    gpio_write(LCD_D5_PORT, LCD_D5_PIN, (data >> 1) & 1);
    gpio_write(LCD_D6_PORT, LCD_D6_PIN, (data >> 2) & 1);
    gpio_write(LCD_D7_PORT, LCD_D7_PIN, (data >> 3) & 1);

    gpio_write(LCD_E_PORT, LCD_E_PIN, HIGH);
    _delay_us(2);

    gpio_write(LCD_E_PORT, LCD_E_PIN, LOW);
    _delay_us(50);
}

void lcd_command(uint8_t command)
{
    gpio_write(LCD_RS_PORT, LCD_RS_PIN, LOW);

    lcd_send_nibble((command >> 4) & 0x0F);
    lcd_send_nibble(command & 0x0F);

    if (command == 0x01 || command == 0x02)
    {
        _delay_ms(2);
    }
}

void lcd_data(uint8_t data)
{
    gpio_write(LCD_RS_PORT, LCD_RS_PIN, HIGH);

    lcd_send_nibble((data >> 4) & 0x0F);
    lcd_send_nibble(data & 0x0F);
}

void lcd_init(void)
{
    pinmode(LCD_RS_PORT, LCD_RS_PIN, OUTPUT);
    pinmode(LCD_E_PORT, LCD_E_PIN, OUTPUT);

    pinmode(LCD_D4_PORT, LCD_D4_PIN, OUTPUT);
    pinmode(LCD_D5_PORT, LCD_D5_PIN, OUTPUT);
    pinmode(LCD_D6_PORT, LCD_D6_PIN, OUTPUT);
    pinmode(LCD_D7_PORT, LCD_D7_PIN, OUTPUT);

    gpio_write(LCD_RS_PORT, LCD_RS_PIN, LOW);
    gpio_write(LCD_E_PORT, LCD_E_PIN, LOW);

    _delay_ms(20);

    // Initialize the LCD in 4-bit mode
    lcd_send_nibble(0x03);
    _delay_ms(5);

    lcd_send_nibble(0x03);
    _delay_us(150);

    lcd_send_nibble(0x03);
    _delay_us(150);

    lcd_send_nibble(0x02);
    _delay_us(150);

    lcd_command(0x28);  // 4-bit, 2 lines
    lcd_command(0x08);  // Display OFF
    lcd_command(0x01);  // Clear display
    lcd_command(0x06);  // Cursor moves right
    lcd_command(0x0C);  // Display ON, cursor OFF
}

void lcd_print(const char *text)
{
    if (text == 0)
    {
        return;
    }

    while (*text != '\0')
    {
        lcd_data((uint8_t)*text);
        text++;
    }
}

void lcd_set_cursor(uint8_t row, uint8_t col)
{
    uint8_t address;

    if (row > 1)
        row = 1;

    if (col > 15)
        col = 15;

    if (row == 0)
        address = 0x80 + col;
    else
        address = 0xC0 + col;

    lcd_command(address);
}

void lcd_clear(void)
{
    lcd_command(0x01);
    _delay_ms(2);
}