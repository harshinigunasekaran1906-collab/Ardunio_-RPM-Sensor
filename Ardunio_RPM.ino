#include <Arduino.h>

#define SENSOR_PIN 3

volatile int pulseCount = 0;   // count pulses
unsigned long lastTime = 0;
int rpm = 0;

int lastState = LOW;
int currentState = LOW;

void setup()
{
    pinMode(SENSOR_PIN, INPUT);
    Serial.begin(9600);
}

void loop()
{
    currentState = digitalRead(SENSOR_PIN);

   
    if (currentState == HIGH && lastState == LOW)
    {
        pulseCount++;
    }

    lastState = currentState;

    // Calculate RPM every 1 second
    if (millis() - lastTime >= 1000)
    {
        rpm = pulseCount * 60;   // pulses/sec × 60

        Serial.print("RPM: ");
        Serial.println(rpm);

        pulseCount = 0;          // reset counter
        lastTime = millis();
    }
}