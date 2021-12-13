#pragma once

#include "consts.hpp"

void setLED(uint8_t idx, uint8_t r, uint8_t g, uint8_t b);
void setLED(uint8_t idx, CRGB color);

void setAllLEDs(uint8_t r, uint8_t g, uint8_t b);
void setAllLEDs(CRGB color);
