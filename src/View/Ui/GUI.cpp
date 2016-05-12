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
  previousPress = currentPress;

  if(touch->dataAvailable())
  {
    if(startWidget)
    {
      touch->read();
      int x = touch->getX();
      int y = touch->getY();
      Serial.println(x);
      Serial.println(y);

      if ((x!=-1) and (y!=-1))
      {

        startWidget->checkHit(x, y, &currentPress);
      }
    }
  }
 else
 {
  currentPress = 0;
 }

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
