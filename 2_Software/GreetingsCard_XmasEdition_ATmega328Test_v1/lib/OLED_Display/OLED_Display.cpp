#include <Arduino.h>
#include "OLED_Display.h"
#include "Bitmaps.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//--------------------------------------
//-- Display Functions
//--------------------------------------
void clearDisplay() {
	display.clearDisplay();
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
}

//--------------------------------------
//-- Draw Functions
//--------------------------------------
void drawMelodyMessage() {
	clearDisplay();
	display.drawBitmap(0, 0, XmasTree_Logo, XMASTREE_LOGO_BMPWIDTH, XMASTREE_LOGO_BMPHEIGHT, WHITE);
	display.drawBitmap(96, 0, XmasTree_Logo, XMASTREE_LOGO_BMPWIDTH, XMASTREE_LOGO_BMPHEIGHT, WHITE);
	display.setCursor(30, 16);
	display.println("Feliz Natal!");
	display.display();
}

void drawAnimationIdle() {
	clearDisplay();
	display.drawBitmap(0, 0, SnowFlake_AnimationIdle, 128, 32, WHITE);
	display.display();
	/* clearDisplay();
	for(uint8_t i=0; i<16; i++) {
		uint8_t pos_x = random(1, 128);
		uint8_t pos_y = random(1, 32);
		display.setCursor(pos_x, pos_y);
		display.println("*");
		display.display();
		delay(25);
	} */
}

void drawAnimation1() {
	clearDisplay();
	display.drawBitmap(0, 0, SnowFlake_Animation1, 128, 32, WHITE);
	display.display();
}

void drawAnimation2() {
	clearDisplay();
	display.drawBitmap(0, 0, SnowFlake_Animation2, 128, 32, WHITE);
	display.display();
}

void drawAnimation3() {
	clearDisplay();
	display.drawBitmap(0, 0, SnowFlake_Animation3, 128, 32, WHITE);
	display.display();
}