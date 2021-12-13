#include "timer.hpp"
#include "lights.hpp"

long currentLength;
uint8_t sectionsToDarken = 0;
CRGB color;
long length, section;
double portion;

void trackTimer(Mode mode, long timerStart) {
    length = getTotalLength(mode);
    section = getSectionLength(mode);
    color = getColor(mode);

    currentLength = GET_MILLIS() - timerStart;
    sectionsToDarken = currentLength / section;
    portion = (double)((length-currentLength) % section) / section;

    setAllLEDs(color);
    for (int i=1; i<=sectionsToDarken; i++) {
        setLED(NUM_LEDS-i, 0,0,0);
    }
    setLED(NUM_LEDS-sectionsToDarken-1 , color.nscale8(255*portion));
}

long getSectionLength(Mode mode) {
    switch (mode)
    {
    case rest:
        return restSection;
    case work:
        return workSection;
    default:
        return unknown;
    }
}
long getTotalLength(Mode mode) {
    switch (mode)
    {
    case rest:
        return restLength;
    case work:
        return workLength;
    default:
        return unknown;
    }
}

CRGB getColor(Mode mode) {
    switch (mode)
    {
    case rest:
        return restColor;
    case work:
        return workColor;
    default:
    return unknown;
    }
}