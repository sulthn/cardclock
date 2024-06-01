#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#include <uRTCLib.h>

#include "defines.h"
#include "display.h"
#include "time.h"
#include "input.h"
#include "state.h"
#include "sync.h"
#include "battery.h"

void setup(void)
{
    wdt_disable();

    Serial.begin(57600);
    Serial.print(F("otanyy clock reset\n"));

    tft.init(240, 240, SPI_MODE3);
    tft.setRotation(1);
    Serial.println(F("initialized display"));

    pinMode(6, OUTPUT);
    analogWrite(6, 5);

    tft.fillScreen(ST77XX_BLACK);

    pinMode(CHG_CHRG, INPUT_PULLUP);
    pinMode(CHG_STDBY, INPUT_PULLUP);

    URTCLIB_WIRE.begin();

    pinMode(RTC_SQW, INPUT_PULLUP);
    pinMode(BDY_SEL1, INPUT_PULLUP);
    pinMode(BDY_SEL2, INPUT_PULLUP);
    pinMode(BDY_LIGHT, INPUT_PULLUP);
    pinMode(BDY_SELECT, INPUT_PULLUP);

    rtc.set_model(URTCLIB_MODEL_DS3231);
    rtc.refresh();

    setupState();

    if (rtc.lostPower())
    {
        lost();
        tft.fillScreen(ST77XX_BLACK);
    }
    setupClock();
    setupSecond();
}

int timeout = 0;

void loop()
{
    uint8_t inputs = readInputs();

    if (inputs & MASK_SEL1)
    {
        Serial.println("SEL1");
        readInputs(true);
        timeout = 0;
    }

    if (inputs & MASK_SEL2)
    {
        Serial.println("SEL2");
        readInputs(true);
        timeout = 0;
    }

    if (!digitalRead(BDY_SELECT))
    {
        Serial.println("TURNING OFF");
        tft.enableDisplay(false);
        tft.enableSleep(true);

        cleanUpRTCInterrupts();

        turnOff();

        tft.enableSleep(false);
        tft.enableDisplay(true);

        setupClock();
        setupSecond();
        timeout = 0;
        Serial.println("TURNING ON");
    }

    if (Serial.available() > 0)
    {
        char byte = Serial.read();
        if (byte == 'S')
        {
            sync();
            tft.fillScreen(ST77XX_BLACK);
            setupClock();
            setupSecond();
        }
        while (Serial.available() > 0)
            Serial.read();
        return;
    }

    if (!onSecond)
        return;

    timeout++;

    

    if (timeout == state.timeout)
    {
        tft.enableDisplay(false);
        tft.enableSleep(true);

        cleanUpRTCInterrupts();

        restTime();

        tft.enableSleep(false);
        tft.enableDisplay(true);

        setupClock();
        setupSecond();

        timeout = 0;
        Serial.println("OUT OF TIMEOUT");
    }

    rtc.refresh();
    Serial.printf("%02d:%02d:%02d\n", rtc.hour(), rtc.minute(), rtc.second());

    if (debug == true)
    {
        tft.setCursor(0, 0);
        tft.print(batteryLevel());
        tft.setCursor(0, 10);
        tft.print("   ");
        tft.setCursor(0, 10);
        tft.print(min(map(batteryLevel() * 100, 3.6 * 100, 4.2 * 100, 0, 100), 100));
        tft.setCursor(0, 20);
        tft.print(digitalRead(CHG_CHRG));
        tft.setCursor(0, 30);
        tft.print(digitalRead(CHG_STDBY));

        Serial.print(batteryLevel());
        Serial.print(" V\n");
        Serial.print(map(batteryLevel() * 100, 3.6 * 100, 4.2 * 100, 0, 100));
        Serial.print("%\n");
        Serial.print("CHRG\n");
        Serial.print(digitalRead(CHG_CHRG));
        Serial.print("\nSTDBY\n");
        Serial.print(digitalRead(CHG_STDBY));
        Serial.print("\nTimeout\n");
        Serial.print(timeout);
        Serial.print("\n\n");
    }

    drawClock();
    onSecond = false;
}
