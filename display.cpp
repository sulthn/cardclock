#include "display.h"

#define TFT_DC 8
#define TFT_RST 9

Adafruit_ST7789 tft = Adafruit_ST7789(-1, TFT_DC, TFT_RST);

void enablePartialDisplay()
{
    // PARTIAL DISPLAY MODE
    tft.writeCommand(0x30);
    tft.spiWrite(64 & 0xFF00);
    tft.spiWrite(64 & 0x00FF);
    tft.spiWrite(176 & 0xFF00);
    tft.spiWrite(176 & 0x00FF);

    tft.writeCommand(0x12);
}

void disablePartialDisplay()
{
    tft.enableDisplay(false);
    tft.writeCommand(0x13);
    tft.enableDisplay(true);
}

const GFXfont *font;
const GFXfont *secondFont;
int scale;
int baseline;
int bufferWidth;
int hoffset;
int offset;

void drawClock()
{
    static int hour   = 0;
    static int minute = 0;
    static int second = 0;

    if (rtc.hour() != hour)
    {
        drawHour();
    }
    if (rtc.hour() != minute)
    {
        drawMinute();
    }

    hour = rtc.hour();
    minute = rtc.minute();
    second = rtc.second();

    drawSecond();
}

void drawHour()
{
    GFXcanvas1 clock(bufferWidth + 4, baseline + 2);

    clock.fillScreen(0);
    clock.setFont(font);
    clock.setCursor(0, baseline);
    clock.setTextColor(1);
    clock.setTextSize(scale);
    clock.printf("%02d", rtc.hour());

    tft.drawBitmap(120 - hoffset / 2, 120 - baseline / 2, clock.getBuffer(), bufferWidth + 4, baseline + 2, 0xFFFF, 0x0000);
}
void drawMinute()
{
    GFXcanvas1 clock(bufferWidth + 4, baseline + 2);

    clock.fillScreen(0);
    clock.setFont(font);
    clock.setCursor(0, baseline);
    clock.setTextColor(1);
    clock.setTextSize(scale);
    clock.printf("%02d", rtc.minute());

    tft.drawBitmap(120 - hoffset / 2 + offset, 120 - baseline / 2, clock.getBuffer(), bufferWidth + 4, baseline + 2, 0xFFFF, 0x0000);
}
void drawSecond()
{

}
/*void drawSecond()
{
    GFXcanvas1 clock(bufferWidth + 4, baseline + 2);

    clock.fillScreen(0);
    clock.setFont(font);
    clock.setCursor(0, baseline);
    clock.setTextColor(1);
    clock.setTextSize(scale);
    clock.printf("%02d", rtc.second());

    tft.drawBitmap(120 - hoffset / 2 + offset + offset, 120 - baseline / 2, clock.getBuffer(), bufferWidth + 4, baseline + 2, 0xFFFF, 0x0000);
}*/

void setupClock()
{
    /*
    0 = timefont
    1 = freemonoserif
    */
    switch ((state.clockSettings & FONT_MASK) >> 7)
    {
    case 1: // 10x14, SCALE 2
        font = &FreeSansBold9pt7b;
        secondFont = &FreeSansBold9pt7b;
        scale = 2;
        baseline = 28;
        hoffset = 88;
        offset = 48;
        bufferWidth = 40;
        break;
    default: // 7x9, SCALE 3
        font = &Time;
        secondFont = nullptr;
        scale = 3;
        baseline = 27;
        hoffset = 105;
        offset = 63;
        bufferWidth = 42;
        break;
    }

    tft.setFont(font);
    tft.setCursor(120 - hoffset / 2, 120 - baseline / 2 + baseline);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(scale);
    tft.print("00:00");

    tft.setFont();
    tft.setTextColor(0xFFFF, 0x0000);
    tft.setTextSize(1);
}

void drawSettings()
{
}
