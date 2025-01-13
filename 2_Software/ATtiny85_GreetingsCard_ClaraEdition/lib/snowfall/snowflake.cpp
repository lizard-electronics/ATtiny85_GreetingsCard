#include <snowflake.h>

c_snowflake::c_snowflake()
{
	Init();
}

void c_snowflake::updatePos()
{
	pos->update(x_speed, y_speed);

	if(pos->getY() >= 4)
	{
		reInit();
	}
}

c_coordinate *c_snowflake::getPos() {return pos;}
uint8_t c_snowflake::getX_speed() {return x_speed;}
uint8_t c_snowflake::getY_speed() {return y_speed;}
const uint8_t *c_snowflake::getImage() {return bmp;}
uint8_t c_snowflake::getSize() {return bmp_size;}