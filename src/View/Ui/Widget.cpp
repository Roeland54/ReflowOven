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

void Widget::drawSingle()
{
  //This method should be implemented in the widget itself.
  //This is only here to provide a default method in case the above is not fulfilled.
}

void Widget::checkHit(int _x, int _y, Widget ** _last)
{
	//pressed = false;

	if(_x >= this->location->x && _x <= this->location->x+this->size->width)
	{
		if(_y >= this->location->y && _y <= this->location->y+this->size->height)
		{
      if(!pressed)
      {
        //Serial.println("Hit with no press before");
			  *_last = (Widget*)this;
        pressed = true;
      }
      //else
        //Serial.println("Hit pressed before");
		}
    else
      pressed = false;
	}
  else
    pressed = false;
 
  if(next)
	  next->checkHit(_x, _y, _last);
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
