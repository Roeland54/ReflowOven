#include "ProgressBar.h"

ProgressBar::ProgressBar(Point * _point, Size * _size) : Widget(_point, _size)
{
	bold = false;
	fontSize = 14;
}

void ProgressBar::draw()
{
	draw(0, 0, false, true);
}

void ProgressBar::draw(int _x, int _y, bool useLoc, bool _drawNext)
{
	int percentagePoint = location->x + (useLoc?_x:0) + (size->width*percentage)/100;
	tft->setColor(VGA_WHITE);
	tft->fillRect(percentagePoint, location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);
	tft->setColor(VGA_BLACK);
	tft->fillRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), percentagePoint, location->y + (useLoc?_y:0) + size->height);
	tft->drawRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);

	if(_drawNext && next)
	{
		if(useLoc)
			next->draw(_x, _y, true, true);
		else
			next->draw();
	}
}

void ProgressBar::setPercentage(int _percentage)
{
	percentage = _percentage;
}
