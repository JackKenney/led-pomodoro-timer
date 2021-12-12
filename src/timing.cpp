#include "consts.hpp"
#include "timing.hpp"

int lastState = HIGH; // assume button is not pressed when plugged in
int currentState;
unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

bool isLongPress()
{
    return (releasedTime - pressedTime >= LONGPRESS_THRESHOLD);
    // || (millis() - pressedTime >= LONGPRESS_THRESHOLD);
}

void setConfig(void shortPressCallback(), void longPressCallback())
{
    // Serial.println("setConfig");
    currentState = digitalRead(BUTTON_PIN);
    if (currentState == LOW)
        Serial.println("PRESSED");

    if (lastState == HIGH && currentState == LOW) // pressed
        pressedTime = millis();
    else if ((lastState == LOW && currentState == HIGH)) // released
    {
        releasedTime = millis();

        if (isLongPress())
            longPressCallback();
        else
            shortPressCallback();
    }
    lastState = currentState;
}