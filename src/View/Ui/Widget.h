#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <UTFT.h>
#include "Point.h"
#include "Size.h"
#include "Fonts.h"

enum Type
{
    INT,
    FLOAT
};

//Save hash of value, on change check hash with previous hash, if changed, redraw.
struct Binding
{
  void * value;
  uint8_t type;
};

class Widget
{
public:
	Widget(Point * _point, Size * size);
	Point * location;
	Size * size;
	uint16_t foreColor;
	uint16_t pressedColor;
	uint16_t backColor;
	uint16_t textColor;
	char * text;
	bool bold;
	int fontSize;
	bool pressed;

	UTFT * tft;

	Widget * next;
	Widget * previous;
	Widget * child;
	Widget * parent;

	virtual void draw();
	virtual void draw(int _x, int _y, bool useLoc, bool _drawNext);
  	virtual void drawSingle();
	virtual void checkHit(int _x, int _y, Widget ** _widget);

	void setNext(Widget * nextwidget);
	void setPrevious(Widget * previouswidget);
	void addChild(Widget * childwidget);
	void setForeColor(int _r, int _g, int _b);
	void setBackColor(int _r, int _g, int _b);
	void setTextColor(int _r, int _g, int _b);
	void setColors(uint16_t _foreColor, uint16_t _backColor, uint16_t _pressedColor, uint16_t _textColor);
	void addBinding(void * value, Type type);
	bool checkBindings();


	Binding values[1];
	uint32_t bindingHashes[1];
	uint32_t hash(uint8_t _index);
};

#endif
