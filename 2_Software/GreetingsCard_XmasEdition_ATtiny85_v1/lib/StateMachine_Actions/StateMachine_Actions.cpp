#include <Arduino.h>
#include "StateMachine_Actions.h"
#include "OLED_Display.h"
#include "Melodies.h"

machine_sate_t state = MELODY;

//--------------------------------------
//-- Actions for each sate
//--------------------------------------
machine_sate_t doIdle() {
	clearDisplay();
	display.println("IDLE");
	//drawAnimationIdle();
	display.display();
	return IDLE;
}

machine_sate_t doAnimation1() {
	clearDisplay();
	display.println("ANIMATION_1");
	//drawAnimation1();
	display.display();
	return ANIMATION_1;
}

machine_sate_t doAnimation2() {
	clearDisplay();
	display.println("ANIMATION_2");
	//drawAnimation2();
	display.display();
	return ANIMATION_2;
}

machine_sate_t doAnimation3() {
	clearDisplay();
	display.println("ANIMATION_3");
	//drawAnimation3();
	display.display();
	return ANIMATION_3;
}

machine_sate_t doMelody() {
	clearDisplay();
  //display.println("MELODY");
	drawMelodyMessage();
	weWishYouMerryXmas();
	return MELODY;
}