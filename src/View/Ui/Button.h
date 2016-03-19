#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Widget.h"
#include "Colors.h"
#include "Size.h"
#include "Point.h"
#include "Fonts.h"

class Button : public Widget
{
public:
	Button(Point * _point, Size * _size, char * text);
	void draw();
	void draw(int _x, int _y, bool useLoc);
};

#endif
