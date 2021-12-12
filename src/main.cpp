#include <Arduino.h>
#include <Button.h>
#include <EEPROM.h>
#include <FastLED.h>

#define SEC_IN_MS(N) (N * 1000l)
#define MIN_IN_MS(N) (N * 60000l)

const uint8_t NUM_LEDS = 5;
CRGB leds[NUM_LEDS];
Button button = Button(5);

bool lightsOn = true;

void setLEDs(uint8_t r, uint8_t g, uint8_t b)
{
  CRGB color = CRGB(r, g, b);
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = color;
  }
}

void setup()
{
  setLEDs(10, 0, 10);
  // setLEDs(0, 0, 0);
  FastLED.addLeds<APA102, MOSI, SCK, BGR>(leds, NUM_LEDS);
  // FastLED.setDither(0);
  // FastLED.clear(true);

  FastLED.show();
}

void loop()
{
  // if (button.pressed())
  // {
  //   if (lightsOn)
  //   {
  //     setLEDs(0, 0, 0);
  //     lightsOn = false;
  //   }
  //   else
  //   {
  //     setLEDs(128, 0, 128);
  //     lightsOn = true;
  //   }
  //   FastLED.addLeds<APA102, MOSI, SCK, BGR>(leds, NUM_LEDS);
  //   FastLED.show();
  // }
}