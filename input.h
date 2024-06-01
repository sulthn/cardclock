#pragma once

#include <Arduino.h>
#include "defines.h"
#include "time.h"

#define MASK_LIGHT 0b00000001
#define MASK_SEL1  0b00000010
#define MASK_SEL2  0b00000100

uint8_t readInputs(bool set = false);
