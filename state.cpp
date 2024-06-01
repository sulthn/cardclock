#include "state.h"

deviceState state = {
    2,          // SERIAL NUMBER
    0,          // REVISION
    "Clock",    // NAME
    0b00000000, // SETTINGS
    0x0000,     // BACKGROUND COLOR
    0xFFFF,     // FOREGROUND COLOR
    600,         // TIMEOUT 600 SECONDS / 10 MIN
    {0}
};

void setupState()
{
    EEPROM.put(0, state);

    Serial.println("-----------------------");
    Serial.println("SERIAL NUMBER");
    Serial.println(state.serialNumber);
    Serial.println("REVISION");
    Serial.println(state.revisionNumber);
    Serial.println("NAME");
    Serial.println(state.name);
    Serial.println("SETTINGS");
    Serial.println(state.clockSettings);
    Serial.println("BACKGROUND COLOR");
    Serial.println(state.backgroundColor);
    Serial.println("FOREGROUND COLOR");
    Serial.println(state.foregroundColor);
    Serial.println("TIMEOUT");
    Serial.println(state.timeout);
    Serial.println("-----------------------");
}
