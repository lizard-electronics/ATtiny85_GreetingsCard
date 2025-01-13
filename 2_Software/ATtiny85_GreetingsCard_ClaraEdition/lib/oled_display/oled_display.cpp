#include <oled_display.h>
#include <Tiny4kOLED.h>

c_display::c_display(uint8_t w, uint8_t h) {}

void c_display::Init()
{
	oled.begin();
	oled.clear();
	oled.setFontX2(FONT6X8CAPS);
	// oled.setFont(FONT8X16);
	// switch the half of RAM that we are writing to,
	// to be the half that is non currently displayed
	// (to make usage of the double buffering)
	oled.switchRenderFrame();
	oled.clear();
	oled.on();
}

void c_display::Clear()
{
	oled.clear();
}

void c_display::Show()
{
	oled.switchFrame();
}

void c_display::WriteFrame()
{
  	DrawBorder();

	oled.setCursor(0, 0);
	// oled.print(F("*                   *")); // FONT6X8
	// oled.print(F("*              *")); // FONT8X16

	// oled.print(F("* Ola Clara :) *"));
	// oled.print(F("*    Ola Clara!     *"));
	// oled.print(F("*        :)         *"));
	oled.print(F("OLA"));
}

void c_display::WriteMessage()
{
	oled.setCursor(0, 0);
	oled.print(F("      Este      "));
	oled.setCursor(0, 2);
	oled.print(F("Microcontrolador"));
}

// Este microcontrolador não tem memória suficiente para 
// expressar o quanto gosto de ti
void c_display::WriteMessageSequence()
{
	uint64_t current_millis = millis();
	static uint64_t previous_millis = 0;

	if(message_sequence == 0 || message_sequence == 1)
	{
		if((message_sequence == 0) ||
			(message_sequence == 1 && current_millis - previous_millis >= 3000))
		{
			previous_millis = current_millis;
			message_sequence = 2;
			
    		Clear();
			DrawBorder();
			oled.setCursor(0, 1);
			// oled.print(F("      Este      "));
			oled.print(F("*       Este        *"));
			oled.setCursor(0, 2);
			oled.print(F("* microcontrolador  *"));
    		Show();
		}
	}
	else if(message_sequence == 2)
	{
		if(current_millis - previous_millis >= 3000)
		{
			previous_millis = current_millis;			
			message_sequence = 3;
			
    		Clear();
			DrawBorder();
			oled.setCursor(0, 1);
			oled.print(F("*  nao tem memoria  *"));
			oled.setCursor(0, 2);
			oled.print(F("*    suficiente     *"));
    		Show();
		}
	}
	else if(message_sequence == 3)
	{
		if(current_millis - previous_millis >= 3000)
		{
			previous_millis = current_millis;			
			message_sequence = 1;
			
    		Clear();
			DrawBorder();
			oled.setCursor(0, 1);
			oled.print(F("*para expressar o qt*"));
			oled.setCursor(0, 2);
			oled.print(F("*  gosto de ti  <3  *"));
    		Show();
		}
	}
}

void c_display::DrawBorder()
{
	// Draw a border around the screen
	oled.setCursor(0, 0);
	oled.startData();
	oled.sendData(0xFF);
	oled.sendData(0xFF);
	oled.sendData(0x7F);
	oled.sendData(0x3F);
	oled.sendData(0x1F);
	oled.sendData(0x0F);
	oled.sendData(0x07);
	oled.repeatData(0x03, 126-14);
	oled.sendData(0x07);
	oled.sendData(0x0F);
	oled.sendData(0x1F);
	oled.sendData(0x3F);
	oled.sendData(0x7F);
	oled.sendData(0xFF);
	oled.sendData(0xFF);
	oled.endData();

	oled.setCursor(0, 1);
	oled.startData();
	oled.sendData(0xFF);
	oled.sendData(0xFF);
	oled.repeatData(0x00, 126-4);
	oled.sendData(0xFF);
	oled.sendData(0xFF);
	oled.endData();

	oled.setCursor(0, 2);
	oled.startData();
	oled.sendData(0xFF);
	oled.sendData(0xFF);
	oled.repeatData(0x00, 126-4);
	oled.sendData(0xFF);
	oled.sendData(0xFF);
	oled.endData();

	oled.setCursor(0, 3);
	oled.startData();
	oled.sendData(0xFF);
	oled.sendData(0xFF);
	oled.sendData(0xFE);
	oled.sendData(0xFC);
	oled.sendData(0xF8);
	oled.sendData(0xF0);
	oled.sendData(0xE0);
	oled.repeatData(0xC0, 126-14);
	oled.sendData(0xE0);
	oled.sendData(0xF0);
	oled.sendData(0xF8);
	oled.sendData(0xFC);
	oled.sendData(0xFE);
	oled.sendData(0xFF);
	oled.sendData(0xFF);
	oled.endData();
}

void c_display::Draw(c_snowflake *pSnowflake)
{
	uint8_t x = pSnowflake->getPos()->getX();
	uint8_t y = pSnowflake->getPos()->getY();
	uint8_t bmp_size = pSnowflake->getSize();
	oled.bitmap(x, y, x+bmp_size, y+1, pSnowflake->getImage());
}

void c_display::Draw(c_snowfall *pSnowfall)
{
	for(uint8_t i=0; i<NUM_FLAKES; i++)
	{
		Draw(&(pSnowfall->snowflakes[i]));
	}
}

// [NOT USED]
void c_display::Remove(c_snowflake *pSnowflake)
{
	Clear();
}
void c_display::Remove(c_snowfall *pSnowfall)
{
	for(uint8_t i=0; i<NUM_FLAKES; i++)
	{
		Remove(&(pSnowfall->snowflakes[i]));
	}
}