#include <Arduino.h>
#include <system_hardware.h>
#include <buzzer_driver.h>
#include <oled_display.h>

// Greetings Card states:
// 0-Idle; 1-Melody 
uint8_t state = 1;

c_display display(OLED_WIDTH, OLED_HEIGHT);
c_snowfall snowfall;


/***************************************
// Aux Functions
***************************************/
void snowfallAnimation()
{
  static bool first_init = true;
  uint64_t current_millis = millis();
	static uint64_t previous_millis = 0;

  if(first_init)
  {
    previous_millis = current_millis;

    display.Draw(&snowfall);
    display.Show();
    first_init = false;
  }
  else if(!first_init && current_millis - previous_millis >= 750)
  {
    previous_millis = current_millis;
    
    display.Clear();
    snowfall.Update();
    display.Draw(&snowfall);
    display.Show();
  }
}


/***************************************
// Main Functions
***************************************/
void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);

  // set to true if initialized with the Melody state
  play_melody = true;
  
  display.Init();
  delay(1000);

  display.Clear();
  display.WriteMessage();
  display.Show();
}

void loop()
{
  if(state == 0)
  {
    snowfallAnimation();

    if(readButton(BUTTON_PIN))
    {
      play_melody = true;
      state = 1;
    
      display.Clear();
      display.WriteMessage();
      display.Show();
    }
  }
  else if(state == 1)
  {
    PlayMelody();

    if(play_melody == false)
    {
      state = 0;
      display.Clear();
    }
  }
}