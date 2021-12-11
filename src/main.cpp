#include <Arduino.h>
#include <Button.h>
#include <EEPROM.h>
#include <FastLED.h>

#define SEC_IN_MS(N) (N * 1000l)
#define MIN_IN_MS(N) (N * 60000l)

const uint8_t NUM_LEDS = 5;
CRGB leds[NUM_LEDS];
CRGB color = CRGB(128, 0, 128);

void setup()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = color;
  }

  FastLED.addLeds<APA102, MOSI, SCK, BGR>(leds, NUM_LEDS);
  // FastLED.setDither(0);
  // FastLED.clear(true);

  FastLED.show();
}

void loop()
{
}