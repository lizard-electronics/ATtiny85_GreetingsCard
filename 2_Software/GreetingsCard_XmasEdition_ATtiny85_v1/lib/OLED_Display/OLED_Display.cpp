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
	for(uint8_t i=0; i<255; i++) {
		display.setCursor(random(1, 128), random(1, 32));
		display.println("*");
		display.display();
	}
}

void drawAnimation1() {
	clearDisplay();
	for(uint8_t i=0; i<255; i++) {
		display.setCursor(random(1, 128), random(1, 32));
		display.println("*");
		display.display();
	}
}

void drawAnimation2() {
	
}

void drawAnimation3() {
	
}