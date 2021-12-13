#pragma once

#include "consts.hpp"
using namespace std;

enum Mode {
    rest = 0,
    work = 1
};

const long workLength = MIN_IN_MS(25);
const long workSection = workLength / 5;

const long restLength = MIN_IN_MS(5);
const long restSection = restLength / 5;

const CRGB workColor = CRGB(128,64,0);
const CRGB restColor = CRGB(32,0,64);

void trackTimer(Mode mode, long timerStart);

long getTotalLength(Mode mode);
long getSectionLength(Mode mode);
CRGB getColor(Mode mode);
