#include "input.h"

#define DEBOUNCE_DELAY 200


uint8_t readInputs(bool set) {
    static uint8_t input = 0;
    static uint8_t last = 0;
    static uint8_t flags = 0;
    static long debounce = 0;
    
    last = input;
    input = ((!digitalRead(BDY_SEL2) & 1) << 2) | ((!digitalRead(BDY_SEL1) & 1) << 1) | (!(digitalRead(BDY_LIGHT) & 1));

    if ((last & MASK_LIGHT) == 0 && (input & MASK_LIGHT) == 1) {
        if ((millis() - debounce) > DEBOUNCE_DELAY)
        {
            Serial.print("LIGHT");
            flags = flags ^ MASK_LIGHT;
            analogWrite(6, 5 + 30 * (flags & MASK_LIGHT));
        }
        debounce = millis();
    }

    if (((last & MASK_SEL1) >> 1) == 0 && ((input & MASK_SEL1) >> 1) == 1) {
        if ((millis() - debounce) > DEBOUNCE_DELAY)
        {
            flags = flags ^ MASK_SEL1;
        }
        debounce = millis();
    }
    

    if (((last & MASK_SEL2) >> 2) == 0 && ((input & MASK_SEL2) >> 2) == 1) {
        if ((millis() - debounce) > DEBOUNCE_DELAY)
        {
            flags = flags ^ MASK_SEL2;
        }
        debounce = millis();
    }

    if (set == true)
    {
        flags = 0;
    }
    

    return flags;
}
