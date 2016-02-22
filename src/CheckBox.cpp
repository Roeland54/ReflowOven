#include "CheckBox.h"
#include "Colors.h"

//Uncomment this if you want the check of the checobox to be an "x"
#define CHECKBOXTEXT

CheckBox::CheckBox(Point * _point, char * _text) : Widget(_point, new Size(10,10))
{
	text = _text;
	bold = false;
	fontSize = 14;
	checked = false;
}

void CheckBox::draw()
{
	draw(0, 0, false);
}

void CheckBox::draw(int _x, int _y, bool useLoc)
{
	tft->setFont(SmallFont);
	tft->setColor(VGA_BLACK);
	tft->setBackColor(VGA_TRANSPARENT);
	tft->setColor(VGA_WHITE);
	tft->fillRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + tft->getFontYsize(), location->y + (useLoc?_y:0) + tft->getFontYsize());
	tft->setColor(VGA_BLACK);
	tft->drawRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + tft->getFontYsize(), location->y + (useLoc?_y:0) + tft->getFontYsize());
#ifndef CHECKBOXTEXT
	if(checked)
		tft->fillRect(location->x + tft->getFontYsize()/4 + (useLoc?_x:0), location->y + tft->getFontYsize()/4 + (useLoc?_y:0), location->x + tft->getFontYsize()/4 + (useLoc?_x:0) + tft->getFontYsize()/2, location->y + tft->getFontYsize()/4 + (useLoc?_y:0) + tft->getFontYsize()/2);
#else
	if(checked)
		tft->print("v", location->x + tft->getFontYsize()/4 + (useLoc?_x:0), location->y + (useLoc?_y:0));
#endif
	tft->print(text, location->x + 2*tft->getFontXsize() + (useLoc?_x:0), location->y + (useLoc?_y:0));
	
	if(next)
	{
		if(useLoc)
			next->draw(_x, _y, true);
		else
			next->draw();
	}
}

void CheckBox::setCheck(bool _checked)
{
	checked = _checked;
}