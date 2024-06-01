#include "sync.h"

bool debug = true;

void sync()
{
    Serial.print("SYNC");
    tft.fillScreen(ST77XX_BLACK);
    
    analogWrite(6, 35);

    tft.setFont();
    tft.setTextSize(3);
    tft.setCursor(120 - (4 * 18) / 2, 120 - 12);
    tft.println("SYNC");

    while (true)
    {
        if (Serial.available() > 0)
        {
            char byte = Serial.read();
            if (byte == 'S')
            {
                Serial.println("lalalala");
                break;
            }
            while (Serial.available() > 0)
                Serial.read();
        }
    }

    tft.setTextSize(1);
    analogWrite(6, 5);
}

void lost()
{
    analogWrite(6, 5);
    tft.setFont();
    tft.setTextSize(2);
    tft.setCursor(120 - (20 * 12) / 2, 120 - 16);
    tft.println("Clock requires sync!");
    tft.setCursor(120 - (14 * 12) / 2, 120);
    tft.println("Connect to app");

    while (true)
    {
        if (Serial.available() > 0)
        {
            char byte = Serial.read();
            if (byte == 'S')
            {
                sync();
                break;
            }
            while (Serial.available() > 0)
                Serial.read();
        }
    }

    rtc.lostPowerClear();
}
