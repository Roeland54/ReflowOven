#include "Label.h"

Label::Label(Point * _point, char * _text) : Widget(_point, new Size(10,10))
{
	text = _text;
	bold = false;
	fontSize = 14;
}

void Label::draw()
{
	draw(0, 0, false, true);
}

void Label::draw(int _x, int _y, bool useLoc, bool _drawNext)
{
	tft->setFont(SmallFont);
	tft->setColor(VGA_BLACK);
	tft->setBackColor(VGA_TRANSPARENT);
	tft->print(text, location->x + (useLoc?_x:0), location->y + (useLoc?_y:0));
	
	if(_drawNext && next)
	{
		if(useLoc)
			next->draw(_x, _y, true, true);
		else
			next->draw();
	}
}
