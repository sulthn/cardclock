#pragma once

#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include "display.h"

float batteryLevel();

// I love resting
void restTime();

void turnOff();
