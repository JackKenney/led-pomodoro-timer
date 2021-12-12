#include "consts.hpp"
#include "timing.hpp"

int lastState = HIGH; // assume button is not pressed when plugged in
int currentState;
unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

bool isLongPress()
{
    return releasedTime - pressedTime >= SEC_IN_MS(0.5);
}

void setConfig(void shortPressCallback(), void longPressCallback())
{
    // Serial.println("setConfig");
    currentState = digitalRead(BUTTON_PIN);
    if (lastState == HIGH && currentState == LOW) // pressed
    {
        // Serial.println("pressing down");
        pressedTime = millis();
    }
    else if (lastState == LOW && currentState == HIGH) // released
    {
        // Serial.println("released");
        releasedTime = millis();

        if (isLongPress())
            longPressCallback();
        else
            shortPressCallback();
    }
    lastState = currentState;
}