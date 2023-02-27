#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED Display width (pixels)
#define SCREEN_HEIGHT 32 // OLED Display height (pixels)

#define OLED_RESET -1

//--------------------------------------
//-- Declarations
//--------------------------------------
extern Adafruit_SSD1306 display;

void clearDisplay();
void drawMelodyMessage();
void drawAnimationIdle();
void drawAnimation1();
void drawAnimation2();
void drawAnimation3();

#endif