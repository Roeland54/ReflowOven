#include "TextBox.h"

TextBox::TextBox(Point * _point, Size * _size, char * _text) : Widget(_point, _size)
{
	text = _text;
	bold = false;
	fontSize = 14;
}

void TextBox::draw()
{
	draw(0, 0, false, true);
}

void TextBox::draw(int _x, int _y, bool useLoc, bool _drawNext)
{
	tft->setFont(SmallFont);
	tft->setColor(VGA_BLACK);
	tft->setBackColor(VGA_TRANSPARENT);
	int textWidth = tft->getFontXsize()*strlen(text);
	int textHeight = tft->getFontYsize();
	tft->setColor(VGA_WHITE);
	tft->fillRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);
	tft->setColor(VGA_BLACK);
	tft->drawRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);
	tft->print(text, location->x + size->width - textWidth + (useLoc?_x:0), location->y + (size->height - textHeight)/2 + (useLoc?_y:0));
	
	if(_drawNext && next)
	{
		if(useLoc)
			next->draw(_x, _y, true, true);
		else
			next->draw();
	}
}
