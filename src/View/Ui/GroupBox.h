#ifndef __GROUPBOX_H__
#define __GROUPBOX_H__

#include "Widget.h"

class GroupBox : public Widget
{
public:
	GroupBox(Point * _point, Size * _size, char * text);
	void draw();
	void draw(int _x, int _y, bool useLoc, bool _drawNext);
	void addChild(Widget * _widget);
	
	char * text;
	bool bold;
	int fontSize;	

	Widget * child;
};

#endif
