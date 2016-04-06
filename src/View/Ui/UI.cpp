#include "UI.h"

UI::UI(UTFT * _tft)
{
	tft = _tft;
}
/*
UI::UI(UTFT * _tft, UTouch * _touch) : UI(_tft)
{
	touch = _touch;
}
*/
UI::UI(UTFT * _tft, UTouch * _touch, Clicked _clickCallback, Clicked _releaseCallback) : UI(_tft)
{
  touch = _touch;
	clickCallback = _clickCallback;
  releaseCallback = _releaseCallback;
}

void UI::addWidget(Widget * _widget)
{
	_widget->tft = tft;

	if(startWidget)
		startWidget->setNext(_widget);
	else
		startWidget = _widget;
}

void UI::draw()
{
	if(startWidget)
		startWidget->draw();
}

void UI::update()
{
	//Widget * last = 0;
  previousPress = currentPress;
  
	if(touch->dataAvailable())
	{
		if(startWidget)
		{
			touch->read();
			int x = touch->getX();
			int y = touch->getY();
			if ((x!=-1) and (y!=-1))
			{
				startWidget->checkHit(x, y, &currentPress);
			}
      //Serial.println("Touch read.");
		}
	}
 else
 {
  currentPress = 0;
 }
 /*
 else
 {
    //No touch found, check for release
    //Serial.println("No touch data available");
    if(previousPress)
    {
      Serial.println("Cleared previousPress");
      previousPress->pressed = false;
      previousPress = 0;
      this->draw();
    }
 }
 */
  if(previousPress != currentPress)
  {
    //Serial.println("Redraw!");
    
    if(previousPress)
      previousPress->pressed = false;
      
    this->draw();
    
    if(currentPress)
     clickCallback(currentPress);
    else
      releaseCallback(previousPress);
  }
}
