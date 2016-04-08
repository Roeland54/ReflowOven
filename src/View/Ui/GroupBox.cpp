#include "GroupBox.h"

GroupBox::GroupBox(Point * _point, Size * _size, char * _text) : Widget(_point, _size)
{
	text = _text;
	bold = false;
	fontSize = 14;
}

void GroupBox::addChild(Widget * _widget)
{
	_widget->tft = tft;

	if(child)
		child->setNext(_widget);
	else
		child = _widget;
}

void GroupBox::draw()
{
	draw(0, 0, false, true);
}

void GroupBox::draw(int _x, int _y, bool useLoc, bool _drawNext)
{
	tft->setColor(VGA_BLACK);
	tft->drawRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0) + tft->getFontYsize()/2, location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);

	tft->setFont(SmallFont);
	tft->setColor(VGA_BLACK);
	tft->setBackColor(VGA_SILVER);
	tft->print(" ", location->x + (useLoc?_x:0) + tft->getFontXsize(), location->y + (useLoc?_y:0));
	tft->print(text, location->x + (useLoc?_x:0) + 2*tft->getFontXsize(), location->y + (useLoc?_y:0));

	if(child)
		child->draw(location->x, location->y + tft->getFontXsize()/2, true, true);

	if(_drawNext && next)
	{
		if(useLoc)
			next->draw(_x, _y, true, true);
		else
			next->draw();
	}
}
