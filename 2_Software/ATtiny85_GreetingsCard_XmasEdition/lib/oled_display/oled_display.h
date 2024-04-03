#ifndef _OLED_DISPLAY_H_
#define _OLED_DISPLAY_H_

#include <Arduino.h>
#include <snowfall.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 32

class c_display
{
private:

public:
	c_display(uint8_t w, uint8_t h);
	// ~c_display();
	void Init();
	void Clear();
	void Show();
	void WriteMessage();
	void Test();
	
	void Draw(c_snowflake *pSnowflake);
	void Draw(c_snowfall *pSnowfall);
	
	void Remove(c_snowflake *pSnowflake);
	void Remove(c_snowfall *pSnowfall);
};

#endif