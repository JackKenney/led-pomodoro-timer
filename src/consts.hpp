#pragma once

#include <Arduino.h>
#include <FastLED.h>

#define SEC_IN_MS(N) (N * 1000l)
#define MIN_IN_MS(N) (N * 60000l)

const uint8_t BUTTON_PIN = 5;
const uint8_t NUM_LEDS = 5;
const uint8_t MAX_BRIGHTNESS = 128;
const long LONGPRESS_THRESHOLD = SEC_IN_MS(0.5);
