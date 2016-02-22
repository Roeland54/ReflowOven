#include "Widget.h"

extern uint8_t SmallFont[];

Widget::Widget(Point * _point, Size * _size)
{
	location = _point;
	size = _size;
}

void Widget::setNext(Widget * _widget)
{
	if(!next)
		this->next = _widget;
	else
		this->next->setNext(_widget);
}

void Widget::setPrevious(Widget * _widget)
{
	this->previous = _widget;
}

void Widget::addChild(Widget * _widget)
{
	this->child = _widget;
}

void Widget::draw()
{
	//This method should be implemented in the widget itself.
	//This is only here to provide a default method in case the above is not fulfilled.
}

void Widget::draw(int _x, int _y, bool _useLoc)
{
	//This method should be implemented in the widget itself.
	//This is only here to provide a default method in case the above is not fulfilled.
}

void Widget::setForeColor(int _r, int _g, int _b)
{

}

void Widget::setBackColor(int _r, int _g, int _b)
{

}

void Widget::setTextColor(int _r, int _g, int _b)
{

}