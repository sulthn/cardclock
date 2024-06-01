#include "time.h"

uRTCLib rtc(0x68);

volatile bool onSecond = false;
void second() {
  onSecond = true;
}

void setupSecond()
{
    rtc.sqwgSetMode(URTCLIB_SQWG_1H);
    attachInterrupt(digitalPinToInterrupt(RTC_SQW), second, RISING);
}

void cleanUpRTCInterrupts() {
    detachInterrupt(digitalPinToInterrupt(RTC_SQW));
    rtc.sqwgSetMode(URTCLIB_SQWG_OFF_0);
}
