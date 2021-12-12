#pragma once

#include "consts.hpp"

bool isLongPress();
void setConfig(void (*shortPressCallback)(), void (*longPressCallback)());
