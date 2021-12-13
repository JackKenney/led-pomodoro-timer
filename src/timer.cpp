#include "timer.hpp"
#include "lights.hpp"

long currentLength;
uint8_t sectionsToDarken = 0;
CRGB color;
long length, section;

void trackTimer(Mode mode, long timerStart) {
    length = getTotalLength(mode);
    section = getSectionLength(mode);
    color = getColor(mode);

    currentLength = GET_MILLIS() - timerStart;
    uint8_t sectionsToDarken = currentLength / restSection;
    double portion = (double)((length-currentLength) % section) / section;

    setAllLEDs(color);
    for (int i=0; i<sectionsToDarken; i++) {
        if (i==sectionsToDarken-1){
            setLED(NUM_LEDS-1-i, color.nscale8(255*portion));            
        }
        else
            setLED(NUM_LEDS-1-i, 0,0,0);
    }
    FastLED.show();
}

long getSectionLength(Mode mode) {
    if (mode == rest)
        return restSection;
    else
        return workSection;
}
long getTotalLength(Mode mode) {
    if (mode == rest)
        return restLength;
    else
        return workLength;
}

CRGB getColor(Mode mode) {
    if (mode == rest)
        return restColor;
    else
        return workColor;
}