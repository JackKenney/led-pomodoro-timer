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
  switch (currentMode)
  {
  case rest:
    currentMode = work;
    break;
  case work:
    currentMode = rest;
    break;
  }
  setAllLEDs(getColor(currentMode));
  timerStart = GET_MILLIS();
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
