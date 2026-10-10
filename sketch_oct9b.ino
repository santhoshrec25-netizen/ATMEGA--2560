#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "gpio.h"
#include "ir.h"
#include "ultrasonic.h"
#include "lcd.h"
#include "buzzer.h"

// ==================================================
// IR SENSOR CONFIGURATION
// ==================================================

#define IR_PORT portb
#define IR_PIN  0

// ==================================================
// ULTRASONIC SENSOR CONFIGURATION
// ==================================================

#define TRIG_PORT portf
#define TRIG_PIN  0

#define ECHO_PORT portk
#define ECHO_PIN  0

// ==================================================
// DISTANCE THRESHOLDS
// ==================================================

#define DANGER_DISTANCE  15
#define NEAR_DISTANCE    30
#define WARNING_DISTANCE 50

// ==================================================
// BUZZER TIMING
// ==================================================

#define FAST_BEEP_MS 200
#define SLOW_BEEP_MS 600

unsigned long previousBeepTime = 0;
bool buzzerState = false;

// ==================================================
// LCD DISPLAY FUNCTION
// ==================================================

void displayParkingStatus(unsigned int distance,
                          bool objectDetected)
{
    char line[17];

    // ----------------------------------------------
    // ROW 1: DISTANCE + IR STATUS
    // ----------------------------------------------

    lcd_set_cursor(0, 0);

    if (distance == 0)
    {
        if (objectDetected)
            lcd_print("D:ERR IR:FOUND  ");
        else
            lcd_print("D:ERR IR:CLEAR  ");
    }
    else
    {
        if (objectDetected)
        {
            snprintf(line, sizeof(line),
                     "D:%ucm IR:FOUND", distance);
        }
        else
        {
            snprintf(line, sizeof(line),
                     "D:%ucm IR:CLEAR", distance);
        }

        lcd_print(line);

        // Clear leftover characters from the previous reading.
        int length = strlen(line);

        while (length++ < 16)
        {
            lcd_print(" ");
        }
    }

    // ----------------------------------------------
    // ROW 2: PARKING STATUS
    // ----------------------------------------------

    lcd_set_cursor(1, 0);

    // Follow your requested IR parking logic.
    if (objectDetected)
    {
        lcd_print("PARKING: FREE   ");
    }
    else if (distance == 0 || distance > WARNING_DISTANCE)
    {
        lcd_print("PARKING: ERROR  ");
    }
    else if (distance < DANGER_DISTANCE)
    {
        lcd_print("PARKING: FULL   ");
    }
    else if (distance <= NEAR_DISTANCE)
    {
        lcd_print("PARK: CAUTION   ");
    }
    else
    {
        lcd_print("PARKING: FREE   ");
    }
}

// ==================================================
// BUZZER CONTROL
// ==================================================

void updateBuzzer(unsigned int distance)
{
    unsigned long currentTime = millis();

    // Invalid reading or distance above 50 cm.
    if (distance == 0 || distance > WARNING_DISTANCE)
    {
        buzzer_off();
        buzzerState = false;
        return;
    }

    // Less than 15 cm: continuous alarm.
    if (distance < DANGER_DISTANCE)
    {
        buzzer_on();
        buzzerState = true;
        return;
    }

    // 15-30 cm: fast beeping.
    // 31-50 cm: slow beeping.
    unsigned long beepInterval;

    if (distance <= NEAR_DISTANCE)
        beepInterval = FAST_BEEP_MS;
    else
        beepInterval = SLOW_BEEP_MS;

    if (currentTime - previousBeepTime >= beepInterval)
    {
        previousBeepTime = currentTime;
        buzzerState = !buzzerState;

        if (buzzerState)
            buzzer_on();
        else
            buzzer_off();
    }
}

// ==================================================
// SETUP
// ==================================================

void setup()
{
    Serial.begin(9600);

    // Initialize IR sensor.
    ir_init(IR_PORT, IR_PIN);

    // Initialize ultrasonic sensor.
    ultrasonic_init(
        TRIG_PORT,
        TRIG_PIN,
        ECHO_PORT,
        ECHO_PIN
    );

    // Initialize LCD and buzzer.
    lcd_init();
    buzzer_init();

    lcd_clear();

    lcd_set_cursor(0, 0);
    lcd_print("SAFETY PARKING");

    lcd_set_cursor(1, 0);
    lcd_print("SYSTEM STARTING");

    delay(1500);

    lcd_clear();
}

// ==================================================
// LOOP
// ==================================================

void loop()
{
    // Read IR sensor.
    bool objectDetected =
        ir_is_detected(IR_PORT, IR_PIN);

    // Read ultrasonic distance.
    unsigned int distance = ultrasonic_read_cm();

    // Update LCD.
    displayParkingStatus(distance, objectDetected);

    // Control buzzer.
    updateBuzzer(distance);

    // Serial Monitor debugging.
    Serial.print("IR: ");
    Serial.print(objectDetected ? "OBJECT FOUND" : "CLEAR");

    Serial.print(" | Distance: ");

    if (distance == 0)
    {
        Serial.println("SENSOR ERROR");
    }
    else
    {
        Serial.print(distance);
        Serial.println(" cm");
    }

    delay(50);
}