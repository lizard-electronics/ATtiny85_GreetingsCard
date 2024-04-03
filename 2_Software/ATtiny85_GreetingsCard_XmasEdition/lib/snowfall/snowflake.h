#ifndef _SNOWFLAKE_H_
#define _SNOWFLAKE_H_

#include <Arduino.h>
#include <coordinate.h>
#include <styles.h>

#define MIN_SPEED 1
#define MAX_SPEED 3

class c_snowflake
{
private:
	c_coordinate *pos;
	uint8_t x_speed = 1;
	uint8_t y_speed = 0;
	const uint8_t *bmp;
	uint8_t bmp_size = 0;

	void composeSnowflake(uint8_t type)
	{
		uint8_t _y_speed = (uint8_t)random(MIN_SPEED, MAX_SPEED);
		switch(type)
		{
			case 0:
				bmp = snowflake1_bmp;
				bmp_size = SNOWFLAKE1_W_H;
				break;
			case 1:
				bmp = snowflake2_bmp;
				bmp_size = SNOWFLAKE2_W_H;
				break;
			// [NOT USED, due to memory limitations]
			// case 2:
			// 	bmp = snowflake3_bmp;
			// 	bmp_size = SNOWFLAKE3_W_H;
			// 	break;

			// [OTHER STYLES...]
			default:
				break;
		}
		y_speed = _y_speed;
	}

	void Init()
	{		
		pos = new c_coordinate();
		composeSnowflake((uint8_t)random(0, N_STYLES));
	}

	void reInit()
	{
		delete pos;
		Init();
	}
	
public:
	c_snowflake();
	// ~c_snowflake();
	void updatePos();
	c_coordinate *getPos();
	uint8_t getX_speed();
	uint8_t getY_speed();
	const uint8_t *getImage();
	uint8_t getSize();
};

#endif