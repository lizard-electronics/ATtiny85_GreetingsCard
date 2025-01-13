#ifndef _SYSTEM_HARDWARE_H_
#define _SYSTEM_HARDWARE_H_

#include <Arduino.h>

/***************************************
// Definition of Parameters
***************************************/
#define OLED_WIDTH 128
#define OLED_HEIGHT 32

/***************************************
// System Pinout
***************************************/
const uint8_t BUZZER_PIN = 3;
const uint8_t BUTTON_PIN = 1;

/***************************************
// Function Declarations
***************************************/
bool readButton(uint8_t pinNumber);

#endif