#ifndef _SNOWFALL_H_
#define _SNOWFALL_H_

#include <Arduino.h>
#include <snowflake.h>

#define NUM_FLAKES 8

class c_snowfall
{
private:

public:
	c_snowfall();
	// ~c_snowfall();
	c_snowflake snowflakes[NUM_FLAKES];
	void Update();
};

#endif