#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__

#include "Widget.h"
#include "Colors.h"
#include "Size.h"
#include "Point.h"
#include "Fonts.h"

class TextBox : public Widget
{
public:
	TextBox(Point * _point, Size * _size, char * text);
	void draw();
	void draw(int _x, int _y, bool useLoc, bool _drawNext);
	
	char * text;
	bool bold;
	int fontSize;	
};

#endif
