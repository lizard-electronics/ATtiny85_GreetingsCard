#include <Arduino.h>
#include <SystemHardware.h>
#include <OLED_Display.h>
#include <StateMachine_Actions.h>
//#include <Melodies.h>

//--------------------------------------
//-- Program Functions
//--------------------------------------
void startSecretMenu() {
	// [In due] Secret Mini-Game

	clearDisplay();
	display.println("[Secret Menu]");
	display.display();
	while (1) {  
	}
}

//--------------------------------------
//-- State Machine flow controller
//--------------------------------------
void startStateMachine() {
	const uint16_t delayTime = 1000;
	static uint64_t lastMillis = 0;

	switch (state) {
		case IDLE:
			doIdle();
			if(readButton(BUTTON_PIN)) {
				state = doMelody();
			}
			if(millis() - lastMillis >= delayTime) {
				lastMillis = millis();
				state = doAnimation1();
			}
			break;

		case ANIMATION_1:
			doAnimation1();
			if(readButton(BUTTON_PIN)) {
				state = doMelody();
			}
			if(millis() - lastMillis >= delayTime) {
				lastMillis = millis();
				state = doAnimation2();
			}
			break;

		case ANIMATION_2:
			doAnimation2();
			if(readButton(BUTTON_PIN)) {
				state = doMelody();
			}
			if(millis() - lastMillis >= delayTime) {
				lastMillis = millis();
				state = doAnimation3();
			}
			break;

		case ANIMATION_3:
			doAnimation3();
			if(readButton(BUTTON_PIN)) {
				state = doMelody();
			}
			if(millis() - lastMillis >= delayTime) {
				lastMillis = millis();
				state = doIdle();
			}
			break;

		case MELODY:
			doMelody();
			lastMillis = millis();
			state = doIdle();
			break;

		default:
			break;
	}
}

//--------------------------------------
//-- Program Main
//--------------------------------------
void setup() {
	//Serial.begin(115200);

	pinMode(TONE_PIN, OUTPUT);
	// Stops the tone playing
	tone(TONE_PIN, 0, 500);

	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
		Serial.println(F("SSD1306 allocation failed"));
		for(;;);
	}
	delay(1000);
	// Display startup message
	clearDisplay();
	display.setCursor(0, 16);
	display.println("Lizard Electronics");
	display.display();

	delay(2000);
	if(digitalRead(BUTTON_PIN))
		startSecretMenu();  // Enters in the Secret Menu
}

void loop() {
	startStateMachine();  // Enters in the State Machine
}