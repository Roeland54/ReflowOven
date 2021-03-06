#include "Label.h"

Label::Label(Point * _point, char * _text) : Widget(_point, new Size(10,10))
{
	text = _text;
	bold = false;
	fontSize = 30;
}

void Label::draw()
{
	draw(0, 0, false, true);
}

void Label::draw(int _x, int _y, bool useLoc, bool _drawNext)
{
	tft->setFont(BigFont);
	tft->setColor(textColor);
	tft->setBackColor(backColor);
	//tft->setBackColor(VGA_TRANSPARENT);
	//tft->print(text, location->x + (useLoc?_x:0), location->y + (useLoc?_y:0));

	char buf[50];
/*
	if(values[0].type == INT)
		sprintf(buf, text, (int)(*(int*)values[0].value)); //Werkt perfect!
	else
		sprintf(buf, text, (float)(*(float*)values[0].value)); //Werkt perfect!

	tft->print(buf, location->x + (useLoc?_x:0), location->y + (useLoc?_y:0));
*/
	if (values[0].type > 0)
	{
	  if(values[0].type == INT)
	    sprintf(buf, text, (int)(*(int*)values[0].value)); //Werkt perfect!
	  else if (values[0].type == FLOAT)
	    sprintf(buf, text, (float)(*(float*)values[0].value)); //Werkt perfect!
		else if (values[0].type == DOUBLE)
	    sprintf(buf, text, (double)(*(double*)values[0].value));
	  tft->print(buf, location->x + (useLoc?_x:0), location->y + (useLoc?_y:0));
	}
	else
	{
		tft->print(buf, location->x + (useLoc?_x:0), location->y + (useLoc?_y:0));
	}


	if(_drawNext && next)
	{
		if(useLoc)
			next->draw(_x, _y, true, true);
		else
			next->draw();
	}
}

void Label::drawSingle()
{
	//Serial.println(this->parent->location->x);
	//Serial.println(this->parent->location->y);
	/*
  if(this->parent)
    this->draw(this->parent->location->x, this->parent->location->y, false, false);
  else
    this->draw(0, 0, false, false);
*/
}
