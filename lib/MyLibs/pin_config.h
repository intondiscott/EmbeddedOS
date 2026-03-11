#pragma once
#ifdef WAVESHARE_OLED_SMARTWATCH
#define XPOWERS_CHIP_AXP2101

#define LCD_SDIO0 4
#define LCD_SDIO1 5
#define LCD_SDIO2 6
#define LCD_SDIO3 7
#define LCD_SCLK 11
#define LCD_CS 12
#define LCD_RESET 8
#define LCD_WIDTH 410
#define LCD_HEIGHT 502

// TOUCH
#define IIC_SDA 15
#define IIC_SCL 14
#define TP_INT 38
#define TP_RESET 9

// SD
const int SDMMC_CLK = 2;
const int SDMMC_CMD = 1;
const int SDMMC_DATA = 3;
const int SDMMC_CS = 17;
#endif
#ifdef M5STACK_CORE2
// M5Stack Core2 LCD Pins
#define LCD_LED_PIN 32
#define LCD_MOSI 23
#define LCD_MISO 38
#define LCD_DC 15
#define LCD_SCLK 18
#define LCD_CS 5
#define LCD_RESET 33
#define LCD_WIDTH 320
#define LCD_HEIGHT 240

// TOUCH
#define IIC_SDA 21
#define IIC_SCL 22
#define TP_INT 39
#define TP_RESET 33

// SD
const int SDMMC_CLK = 2;
const int SDMMC_CMD = 1;
const int SDMMC_DATA = 3;
const int SDMMC_CS = 17;

#endif