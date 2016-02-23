#include "Button.h"

Button::Button(Point * _point, Size * _size, char * _text) : Widget(_point, _size)
{
	text = _text;
	bold = false;
	fontSize = 14;
}

void Button::draw()
{
	draw(0, 0, false);
}

void Button::draw(int _x, int _y, bool useLoc)
{
	tft->setFont(SmallFont);
	tft->setColor(VGA_BLACK);
	tft->setBackColor(VGA_TRANSPARENT);
	int textWidth = tft->getFontXsize()*strlen(text);
	int textHeight = tft->getFontYsize();
	tft->drawRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);
	tft->print(text, location->x + (size->width - textWidth)/2 + (useLoc?_x:0), location->y + (size->height - textHeight)/2 + (useLoc?_y:0));
	
	if(next)
	{
		if(useLoc)
			next->draw(_x, _y, true);
		else
			next->draw();
	}
}