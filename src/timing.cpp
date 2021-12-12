#include "consts.hpp"
#include "timing.hpp"

int lastState = HIGH; // assume button is not pressed when plugged in
int currentState;
unsigned long pressedTime = 0;
unsigned long releasedTime = 0;
bool longPressCalledEarly = false;

bool isLongPress(bool held)
{
    if (held)
        return (millis() - pressedTime >= LONGPRESS_THRESHOLD);
    else 
        return (releasedTime - pressedTime >= LONGPRESS_THRESHOLD);
}

void setConfig(void shortPressCallback(), void longPressCallback())
{
    // Serial.println("setConfig");
    currentState = digitalRead(BUTTON_PIN);
    
    if (lastState == HIGH && currentState == LOW) // pressed
        pressedTime = millis();
    else if(lastState == LOW && currentState == LOW) {
        if (isLongPress(true)){
            longPressCallback();
            longPressCalledEarly = true;
        }
    }    
    else if (lastState == LOW && currentState == HIGH) // released
    {
        if (longPressCalledEarly) {
            longPressCalledEarly = false;
            lastState = currentState;
            return;
        }
        releasedTime = millis();
        if (isLongPress(false))
            longPressCallback();
        else
            shortPressCallback();
    }
    lastState = currentState;
}