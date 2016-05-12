#ifndef __CHECKBOX_H__
#define __CHECKBOX_H__

#include "Widget.h"
#include "Colors.h"
#include "Size.h"
#include "Point.h"
#include "Fonts.h"

class CheckBox : public Widget
{
public:
	CheckBox(Point * _point, char * text);
	void draw();
	void draw(int _x, int _y, bool useLoc, bool _drawNext);
	
	bool checked;
	void setCheck(bool _checked);
};

#endif
