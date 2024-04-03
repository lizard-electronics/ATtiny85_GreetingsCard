#ifndef _COORDINATES_H_
#define _COORDINATES_H_

#include <Arduino.h>

class c_coordinate
{
private:
	uint8_t x = 0;
	uint8_t y = 0;

public:
	c_coordinate();
	// ~c_coordinate();
	void update(uint8_t x_pixel, uint8_t y_pixel);
	uint8_t getX();
	uint8_t getY();
};

#endif