#ifndef __PANEL_H__
#define __PANEL_H__

#include "Widget.h"

class Panel : public Widget
{
public:
	Panel(Point * _point, Size * _size);
	void draw();
	void draw(int _x, int _y, bool useLoc);
	
	void addChild(Widget * _widget);

	Widget * child;
};

#endif
