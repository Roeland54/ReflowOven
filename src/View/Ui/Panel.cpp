#include "Panel.h"

Panel::Panel(Point * _point, Size * _size) : Widget(_point, _size)
{
}

void Panel::addChild(Widget * _widget)
{
	_widget->tft = tft;

	if(child)
		child->setNext(_widget);
	else
		child = _widget;
}

void Panel::draw()
{
	draw(0, 0, false, true);
}

void Panel::draw(int _x, int _y, bool useLoc, bool _drawNext)
{
	tft->setColor(VGA_RED);
	tft->fillRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);

	if(child)
		child->draw(location->x, location->y, true, true);

	if(_drawNext && next)
	{
		if(useLoc)
			next->draw(_x, _y, true, true);
		else
			next->draw();
	}
}
