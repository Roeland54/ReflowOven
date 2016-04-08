#include "GUI.h"

GUI::GUI(UTFT * _tft)
{
  tft = _tft;
}
/*
GUI::GUI(UTFT * _tft, UTouch * _touch) : GUI(_tft)
{
  touch = _touch;
}
*/
GUI::GUI(UTFT * _tft, UTouch * _touch, Clicked _clickCallback, Clicked _releaseCallback) : GUI(_tft)
{
  touch = _touch;
  clickCallback = _clickCallback;
  releaseCallback = _releaseCallback;
}

void GUI::addWidget(Widget * _widget)
{
  _widget->tft = tft;

  if(startWidget)
    startWidget->setNext(_widget);
  else
    startWidget = _widget;
}

void GUI::draw()
{
  if(startWidget)
    startWidget->draw();
}

void GUI::update()
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
    if(currentPress)
    {
      currentPress->pressed = true;
      currentPress->drawSingle();
      clickCallback(currentPress);
    }
    else
    {
      previousPress->pressed = false;
      previousPress->drawSingle();
      releaseCallback(previousPress);
    }
  }
}
