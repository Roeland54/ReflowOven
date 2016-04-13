#include "Button.h"

Button::Button(Point * _point, Size * _size, char * _text) : Widget(_point, _size)
{
	text = _text;
	bold = false;
	fontSize = 14;
}

void Button::draw()
{
	draw(0, 0, false, true);
}

void Button::draw(int _x, int _y, bool useLoc, bool _drawNext)
{
  tft->setFont(SmallFont);
  tft->setColor(foreColor);
  tft->setBackColor(backColor);
  int textWidth = tft->getFontXsize()*strlen(text);
  int textHeight = tft->getFontYsize();
 
  if(pressed)
  {
    tft->setColor(pressedColor);
  }
  else
  {
    tft->setColor(foreColor);
  }

  tft->fillRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);
  tft->setColor(backColor);
  tft->drawRect(location->x + (useLoc?_x:0), location->y + (useLoc?_y:0), location->x + (useLoc?_x:0) + size->width, location->y + (useLoc?_y:0) + size->height);
  if(pressed)
  {
    tft->setBackColor(pressedColor);
  }
  else
  {
    tft->setBackColor(foreColor);
  }
  tft->setColor(textColor);

  char buf[50];
  if(values[0].type == INT)
    sprintf(buf, text, (int)(*(int*)values[0].value)); //Werkt perfect!
  else
    sprintf(buf, text, (float)(*(float*)values[0].value)); //Werkt perfect!

  tft->print(buf, location->x + (size->width - textWidth)/2 + (useLoc?_x:0), location->y + (size->height - textHeight)/2 + (useLoc?_y:0));
  
	if(_drawNext && next)
	{
		if(useLoc)
			next->draw(_x, _y, true, true);
		else
			next->draw();
	}
}

void Button::drawSingle()
{
  if(this->parent)
    this->draw(this->parent->location->x, this->parent->location->y, true, false);
  else
    this->draw(0, 0, false, false);
}