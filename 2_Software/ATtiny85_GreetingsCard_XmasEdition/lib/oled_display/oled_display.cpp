#include <oled_display.h>
#include <Tiny4kOLED.h>

c_display::c_display(uint8_t w, uint8_t h) {}

void c_display::Init()
{
	oled.begin();
  oled.clear();
  // switch the half of RAM that we are writing to,
  // to be the half that is non currently displayed
  // (to make usage of the double buffering)
  oled.switchRenderFrame();
	oled.clear();
  oled.on();

	// [DEBUG]
	// oled.setFont(FONT6X8);
  // oled.setCursor(12, 0);
  // oled.print(F("Started"));
	// oled.switchFrame();
}
void c_display::Clear()
{
	oled.clear();
}
void c_display::Show()
{
	oled.switchFrame();
}
void c_display::WriteMessage()
{
	oled.setFont(FONT8X16);
  oled.setCursor(0, 0);
  for(int i=0; i<16; i++){
   oled.print('/');
  }
  oled.setCursor(0, 3);
  for(int i=0; i<16; i++){
   oled.print('/');
  }
  oled.setFont(FONT8X16);
  oled.setCursor(0, 1);
  // oled.print(F("* Feliz Natal! *"));	
	oled.print(F("* Boas Festas! *"));
}
void c_display::Test()
{
	for(uint8_t i=0; i<NUM_FLAKES; i++)
	{
		oled.bitmap(i, 0, 1 + i, 1, snowflake1_bmp);
	}
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