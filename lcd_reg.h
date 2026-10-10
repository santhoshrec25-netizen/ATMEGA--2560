#ifndef LCD_REG_H
#define LCD_REG_H

// RS pin: Arduino Mega D2 = PE4
#define LCD_RS_PORT porte
#define LCD_RS_PIN  4

// Enable pin: Arduino Mega D3 = PE5
#define LCD_E_PORT  porte
#define LCD_E_PIN   5

// LCD data pins
// D4: Arduino Mega D21 = PD0
#define LCD_D4_PORT portd
#define LCD_D4_PIN  0

// D5: Arduino Mega D20 = PD1
#define LCD_D5_PORT portd
#define LCD_D5_PIN  1

// D6: Arduino Mega D19 = PD2
#define LCD_D6_PORT portd
#define LCD_D6_PIN  2

// D7: Arduino Mega D18 = PD3
#define LCD_D7_PORT portd
#define LCD_D7_PIN  3

#endif