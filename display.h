#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#include "time.h"
#include "state.h"

#include "timefont.h"
#include "Fonts/FreeSansBold9pt7b.h"

extern Adafruit_ST7789 tft;

void enablePartialDisplay();

void disablePartialDisplay();


// CLOCK
void drawClock();

void drawHour();
void drawMinute();
void drawSecond();

void setupClock();

// SETTINGS
void drawSettings();
