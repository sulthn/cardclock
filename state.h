#pragma once

#include <stdint.h>
#include <EEPROM.h>

#include <Arduino.h>

#define FONT_MASK 0b10000000
#define HOUR_MASK 0b01000000
#define HOUR_MASK 0b00100000

struct timer
{
    char name[32] = { '\0' };
    uint8_t hour;
    uint8_t minute;
    uint8_t second;

    uint8_t tHour;
    uint8_t tMinute;
    uint8_t tSecond;
};

struct deviceState
{
    uint32_t serialNumber;
    uint32_t revisionNumber;
    char name[32]  =  { '\0' };

    int clockSettings;
    uint16_t backgroundColor;
    uint16_t foregroundColor;
    int timeout;

    timer   timers[3];
};

extern deviceState state;

void setupState();
