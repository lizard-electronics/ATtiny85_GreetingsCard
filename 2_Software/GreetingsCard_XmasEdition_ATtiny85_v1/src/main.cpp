#include <Arduino.h>
#include <SystemHardware.h>
#include <OLED_Display.h>
#include <StateMachine_Actions.h>

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
				//state = doAnimation2();
				state = doIdle();
			}
			break;
/* 
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
 */
		case MELODY:
			doMelody();
			lastMillis = millis();
			state = doIdle();
			break;

		default:
			break;
	}
}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}