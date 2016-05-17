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
  startWidget = NULL;

  currentPress = NULL;
  previousPress = NULL;
}

void GUI::addWidget(Widget * _widget)
{
  _widget->tft = tft;

  if(startWidget != NULL)
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
  Serial.println("gui update started");

  if(touch->dataAvailable())
  {
    Serial.println("Touch detected");
    //delay(100);
    if(startWidget != NULL)
    {
      Serial.println("startWidget != NULL");
      touch->read();
      Serial.println("touch read");
      delay(100);
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

 Serial.print("currentPress: ");
 Serial.println((int)currentPress);
 delay(100);
 Serial.print("previousPress: ");
 Serial.println((int)previousPress);
 delay(100);

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
