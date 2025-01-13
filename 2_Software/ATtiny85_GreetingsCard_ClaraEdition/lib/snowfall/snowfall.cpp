#include <snowfall.h>

c_snowfall::c_snowfall() {}

void c_snowfall::Update()
{
	for(uint8_t i=0; i<NUM_FLAKES; i++)
	{
		snowflakes[i].updatePos();
	}
}