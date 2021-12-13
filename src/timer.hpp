#pragma once

#include "consts.hpp"

enum Mode {
    rest = 0,
    work = 1,
    unknown = 2
};

const CRGB workColor = CRGB(128,64,0);
const long workLength = MIN_IN_MS(25);
const long workSection = workLength / 5;

const CRGB restColor = CRGB(32,0,64);
const long restLength = MIN_IN_MS(5);
const long restSection = restLength / 5;

void trackTimer(Mode mode, long timerStart);

long getTotalLength(Mode mode);
long getSectionLength(Mode mode);
CRGB getColor(Mode mode);
