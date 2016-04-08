#ifndef __GUI_H__
#define __GUI_H__

#include "Widget.h"
#include <UTFT.h>
#include <UTouch.h>
#include "Fonts.h"
#include "Button.h"
#include "Label.h"
#include "TextBox.h"
#include "CheckBox.h"
#include "ProgressBar.h"
#include "Panel.h"
#include "GroupBox.h"

typedef void (*Clicked)(Widget*);

class GUI
{
public:
  GUI(UTFT * _tft);
  //GUI(UTFT * _tft, UTouch * _touch);
  GUI(UTFT * _tft, UTouch * _touch, Clicked _clickCallback, Clicked _releaseCallback);

  Widget * startWidget;
  UTFT * tft;
  UTouch * touch;

  Clicked clickCallback;
    Clicked releaseCallback;

    Widget * currentPress;
  Widget * previousPress;

  void draw();
  void update();
  void addWidget(Widget * _widget);
};

#endif
