#include "system_hardware.h"

/***************************************
// Button Debounce
***************************************/
bool readButton(uint8_t pinNumber)
{
  static bool buttonState;             // current reading from the input pin
  static bool lastButtonState = false; // previous reading from the input pin
  bool inputState = false;             // input state to return

  static uint64_t lastDebounceTime = 0; // last time output pin was debounced
  uint8_t debounceDelay = 20;           // debounce time [ms]

  // read the state of the switch
  bool reading = digitalRead(pinNumber);

  // if the switch changed, due to noise or pressing:
  if (reading != lastButtonState) 
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  // if not, ignores the noise between the debounceDelay
  if ((millis() - lastDebounceTime) >= debounceDelay) 
  {
    // if the button state has changed,
    // take reading as the actual current state
    if (reading != buttonState) 
    {
      buttonState = reading;
      if (buttonState == true) 
      {
        inputState = !inputState; // only outputs true if buttonState == true
      }
    }
  }
  // save the reading,
  // next time through the loop it'll be the lastButtonState
  lastButtonState = reading;
  return inputState;
}