#include <Arduino.h>
#include "SystemHardware.h"

//--------------------------------------
//-- Hardware Functions
//--------------------------------------
int readButton(int pinNumber){
  static int buttonState;           // Current reading from the input pin
  static int lastButtonState = LOW; // Previous reading from the input pin
  int inputState = LOW;             // Input state to return

  static unsigned long lastDebounceTime = 0;  // Last time the output pin was toggled
  unsigned long debounceDelay = 20;           // Debounce time [ms]

  // Read the state of the switch
  int reading = digitalRead(pinNumber);

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  // If not, ignores the noise between the debounceDelay
  if ((millis() - lastDebounceTime) >= debounceDelay) {
    // If the button state has changed, take reading as the actual current state
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        inputState = !inputState; // Only outputs HIGH if buttonState == HIGH
      }
    }
  }
  // Save the reading, next time through the loop it'll be the lastButtonState
  lastButtonState = reading;
  return inputState;
}