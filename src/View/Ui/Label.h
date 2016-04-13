#ifndef __LABEL_H__
#define __LABEL_H__

#include "Widget.h"
#include "Colors.h"
#include "Size.h"
#include "Point.h"
#include "Fonts.h"

class Label : public Widget
{
public:
	Label(Point * _point, char * text);
	void draw();
	void draw(int _x, int _y, bool useLoc, bool _drawNext);
	void drawSingle();
};

#endif
