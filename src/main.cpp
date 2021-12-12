#include "consts.hpp"
#include "timing.hpp"
#include "lights.hpp"

void setup()
{
  setAllLEDs(10, 0, 10);
  FastLED.show();

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void shortPress()
{
  // Serial.println("shortPress");
  setAllLEDs(
    rand() % MAX_BRIGHTNESS, 
    rand() % MAX_BRIGHTNESS, 
    rand() % MAX_BRIGHTNESS
  );
  FastLED.show();
}

void longPress()
{
  // Serial.println("longPress");
  setAllLEDs(0, 0, 0);
  FastLED.show();
}

void loop()
{
  setConfig(shortPress, longPress);
}
