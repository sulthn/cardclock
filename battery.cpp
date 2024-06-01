#include "battery.h"

#define batteryPin A0

float batteryLevel()
{
    return (33.0 * analogRead(batteryPin))/5120.0;
}

void restTime()
{
    delay(100);
    PCMSK2 |= (1 << PCINT23);
    PCIFR = 0b00000111;
    
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    PCICR |= (1 << PCIE2);
    sleep_mode();
    sleep_disable();

    PCMSK2 &= ~(1 << PCINT23);
}

ISR(PCINT2_vect)
{
    PCICR &= ~(1 << PCIE2);
}

void turnOff()
{
    delay(100);

    PCMSK2 |= (1 << PCINT21);
    PCIFR = 0b00000111;
    
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    PCICR |= (1 << PCIE2);
    sleep_mode();
    sleep_disable();

    PCMSK2 &= ~(1 << PCINT21);
}
