#include "Color.h"

Color::Color()
{
  
}

Color::Color(int _r, int _g, int _b)
{
	r = _r;
	g = _g;
	b = _b;

	update();
}

void Color::update()
{
	rgb888 = (r << 16) | (g << 8) | b;
	rgb565 = (r << 11) | (g << 5) | b;
}
