#ifndef _OLED_DISPLAY_H_
#define _OLED_DISPLAY_H_

#include <Arduino.h>
#include <system_hardware.h>
#include <snowfall.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 32

class c_display
{
private:

public:
	c_display(uint8_t w, uint8_t h);
	// ~c_display();

	// message sequence states
	uint8_t message_sequence = 0;

	void Init();
	void Clear();
	void Show();
	void WriteFrame();
	void WriteMessage();
	void DrawBorder();
	void WriteMessageSequence();
	
	void Draw(c_snowflake *pSnowflake);
	void Draw(c_snowfall *pSnowfall);
	
	void Remove(c_snowflake *pSnowflake);
	void Remove(c_snowfall *pSnowfall);
};

#endif