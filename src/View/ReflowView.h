#ifndef __REFLOWVIEW_H__
#define __REFLOWVIEW_H__

#include <UTFT.h>
#include <UTouch.h>
#include "../View/Ui/GUI.h"
#include "../Config.h"

class ReflowView
{
  public:
    ReflowView();
    ReflowView(ClickedCallbackPointer press, ClickedCallbackPointer release);
    UTFT *tft;
    UTouch *touch;
    GUI *gui;
    void Update();
    void pressCallBack(Widget * _widget);
    void releaseCallBack(Widget * _widget);
  private:
    void DrawStartupPage();
    Button *onBtn;
};

#endif
