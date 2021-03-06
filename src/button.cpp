#include "consts.hpp"
#include "button.hpp"

int lastState = HIGH; // assume button is not pressed when plugged in
int currentState = HIGH; // assume button is not pressed when plugged in
unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

bool isLongPress()
{
        return (GET_MILLIS() - pressedTime >= LONGPRESS_THRESHOLD);
}

void watchButton(void shortPressCallback(), void longPressCallback())
{
    if (GET_MILLIS() - releasedTime < DELAY_LENGTH)
        return;

    currentState = digitalRead(BUTTON_PIN);

    // pressed
    if (lastState == HIGH && currentState == LOW) {
        pressedTime = GET_MILLIS();
    }

    // held
    else if(lastState == LOW && currentState == LOW) {
        if (isLongPress()){
            longPressCallback();
        }
    }

    // released
    else if (lastState == LOW && currentState == HIGH)
    {
        if (isLongPress())
            longPressCallback();
        else
            shortPressCallback();

        releasedTime = GET_MILLIS();
        pressedTime = GET_MILLIS();

    }
    lastState = currentState;
}
