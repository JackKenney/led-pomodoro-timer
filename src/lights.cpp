#include "lights.hpp"

CRGB leds[NUM_LEDS];

void setLED(uint8_t idx, uint8_t r, uint8_t g, uint8_t b)
{
    CRGB color = CRGB(r, g, b);
    setLED(idx, color);
}

void setLED(uint8_t idx, CRGB color)
{
    leds[idx] = color;
    FastLED.addLeds<APA102, MOSI, SCK, BGR>(leds, NUM_LEDS);
}

void setAllLEDs(uint8_t r, uint8_t g, uint8_t b)
{
    setAllLEDs(CRGB(r,g,b));
}


void setAllLEDs(CRGB color)
{
    for (int i = 0; i < NUM_LEDS; i++)
        setLED(i, color);
}
