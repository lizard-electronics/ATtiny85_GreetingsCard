#include <Arduino.h>
#include <system_hardware.h>
#include <buzzer_driver.h>
// #include <oled_display.h>
#include <TinyOzOLED.h>
#include <snowfall.h>

// Greetings Card states:
static uint8_t state = 0;

c_snowfall snowfall;


/***************************************
// Aux Functions
***************************************/
void Draw(c_snowflake *pSnowflake)
{
	uint8_t x = pSnowflake->getPos()->getX();
	uint8_t y = pSnowflake->getPos()->getY();
	// uint8_t bmp_size = pSnowflake->getSize();
  OzOled.drawBitmap(pSnowflake->getImage(), x, y, 1, 1);
}

void Draw(c_snowfall *pSnowfall)
{
	for(uint8_t i=0; i<NUM_FLAKES; i++)
	{
		Draw(&(pSnowfall->snowflakes[i]));
	}
}

void snowfallAnimation()
{
  static bool first_init = true;
  uint64_t current_millis = millis();
	static uint64_t previous_millis = 0;

  if(first_init)
  {
    previous_millis = current_millis;
    first_init = false;
    
    OzOled.clearDisplay();
    Draw(&snowfall);
  }
  else if(!first_init && current_millis - previous_millis >= 1000)
  {
    previous_millis = current_millis;
    
    OzOled.clearDisplay();
    snowfall.Update();
    Draw(&snowfall);
  }
}


/***************************************
// Main Functions
***************************************/
void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  OzOled.init();
  
	OzOled.sendCommand(0xA8); //set multiplexer
	OzOled.sendCommand(0x1F); //32 lines
	OzOled.sendCommand(0xDA); //set COM pins
	OzOled.sendCommand(0x02); //pins

  OzOled.clearDisplay(); 
  OzOled.setNormalDisplay();
  OzOled.sendCommand(0xA1);
  OzOled.sendCommand(0xC8);
  OzOled.setHorizontalMode(); 
  OzOled.setBrightness(255);

  OzOled.clearDisplay();
  OzOled.drawBitmap(bmp_message0_128x32, 0, 0, 16, 4);
  delay(1000);
}

void loop()
{
  if(state == 0)
  {
    if(readButton(BUTTON_PIN))
    {
      state = 1;

      OzOled.clearDisplay();
      OzOled.drawBitmap(bmp_message1_128x32, 0, 0, 16, 4);
    }
  }
  else if(state == 1)
  {
    if(readButton(BUTTON_PIN))
    {
      state = 2;

      OzOled.clearDisplay();
      OzOled.drawBitmap(bmp_message2_128x32, 0, 0, 16, 4);
    }
  }
  else if(state == 2)
  {
    if(readButton(BUTTON_PIN))
    {
      state = 3;

      OzOled.clearDisplay(); 
      OzOled.setCursorXY(0,3);
      OzOled.drawBitmap(bmp_message3_128x32, 0, 0, 16, 4);
    }
  }
  else if(state == 3)
  {
    if(readButton(BUTTON_PIN))
    {
      state = 4;
    }
  }
  else if(state == 4)
  {
    snowfallAnimation();

    if(readButton(BUTTON_PIN))
    {
      state = 0;

      OzOled.clearDisplay();
      OzOled.drawBitmap(bmp_message0_128x32, 0, 0, 16, 4);
    }
  }
}