#include "consts.hpp"
#include "button.hpp"
#include "lights.hpp"
#include "timer.hpp"

Mode currentMode = rest;
long timerStart = 0;

void setup()
{
  timerStart = GET_MILLIS();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  FastLED.show();
}

void shortPress()
{
  if (currentMode == rest) {
      currentMode = work;
      setAllLEDs(getColor(currentMode));
    }
  else {
      currentMode = rest;
      setAllLEDs(getColor(currentMode));
    }
}

void longPress()
{
  timerStart = GET_MILLIS();
}

void loop()
{
  watchButton(shortPress, longPress);
  EVERY_N_MILLIS(8) {
    trackTimer(currentMode, timerStart);
  }
  
  FastLED.show();
}
