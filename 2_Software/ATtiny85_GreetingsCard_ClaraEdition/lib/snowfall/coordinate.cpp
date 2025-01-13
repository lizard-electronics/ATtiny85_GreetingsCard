#include <coordinate.h>

c_coordinate::c_coordinate()
{
	// x = (uint8_t)random(0, 127);
	x = (uint8_t)random(0, 15);
	y = 0;
}

void c_coordinate::update(uint8_t x_pixel, uint8_t y_pixel)
{
	x += x_pixel;
	y += y_pixel;
}

uint8_t c_coordinate::getX() {return x;}
uint8_t c_coordinate::getY() {return y;}