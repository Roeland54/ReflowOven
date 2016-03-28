#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <UTFT.h>
#include "Point.h"
#include "Size.h"
#include "Fonts.h"

class Widget
{
public:
	Widget(Point * _point, Size * size);
	Point * location;
	Size * size;
	int foreColor;
	int backColor;
	int textColor;
	char * text;
	bool bold;
	int fontSize;

	UTFT * tft;

	Widget * next;
	Widget * previous;
	Widget * child;

	virtual void draw();
	virtual void draw(int _x, int _y, bool useLoc);
	void checkHit(int _x, int _y, Widget ** _widget);

	void setNext(Widget * nextwidget);
	void setPrevious(Widget * previouswidget);
	void addChild(Widget * childwidget);
	void setForeColor(int _r, int _g, int _b);
	void setBackColor(int _r, int _g, int _b);
	void setTextColor(int _r, int _g, int _b);
};

#endif
