#pragma once

#include <uRTCLib.h>

#include "defines.h"

extern uRTCLib rtc;

extern volatile bool onSecond;

void setupSecond();

void cleanUpRTCInterrupts();
