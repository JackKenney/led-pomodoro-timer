#include <Arduino.h>
// #include <Button.h>
#include <EEPROM.h>
#include <FastLED.h>

#define SEC_IN_MS(N) (N * 1000l)
#define MIN_IN_MS(N) (N * 60000l)

const uint8_t BUTTON_PIN = 5;
const uint8_t NUM_LEDS = 5;
CRGB leds[NUM_LEDS];
const uint8_t MAX_BRIGHTNESS = 128;
// Button button = Button(5);

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

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

int lastState = HIGH;
int currentState;
unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

bool isLongPress()
{
  return releasedTime - pressedTime >= SEC_IN_MS(0.5);
}

void loop()
{
  currentState = digitalRead(BUTTON_PIN);
  if (lastState == HIGH && currentState == LOW) // pressed
  {
    pressedTime = millis();
  }
  else if (lastState == LOW && currentState == HIGH) // released
  {
    releasedTime = millis();

    if (isLongPress())
    {
      setLEDs(0, 0, 0);
      FastLED.addLeds<APA102, MOSI, SCK, BGR>(leds, NUM_LEDS);
    }
    else
    {
      setLEDs(rand() % MAX_BRIGHTNESS, rand() % MAX_BRIGHTNESS, rand() % MAX_BRIGHTNESS);
      FastLED.addLeds<APA102, MOSI, SCK, BGR>(leds, NUM_LEDS);
    }
  }
  FastLED.show();
  lastState = currentState;
}