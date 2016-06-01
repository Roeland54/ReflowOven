#ifndef __REFLOWVIEW_H__
#define __REFLOWVIEW_H__

#include <UTFT.h>
#include <UTouch.h>
#include "../View/Ui/GUI.h"
#include "../Config.h"
#include "../settingClasses/ReflowCurveSettings.h"

class ReflowView
{
  public:
    ReflowView();
    ReflowView(
      ClickedCallbackPointer press,
      ClickedCallbackPointer release,
      float *wantedTemp,
      float *realTemp,
      ReflowCurveSettings *curve
    );
    UTFT *tft;
    UTouch *touch;
    GUI *gui;
    void Update();
    void pressCallBack(Widget * _widget);
    void releaseCallBack(Widget * _widget);
  private:
    float *wantedTemp;
    float *realTemp;

    void DrawStartupPage();
    void DrawFlowPage();
    void DrawSetPage();

    ReflowCurveSettings * curve;

    Button * onBtn;
    Button * offBtn;
    Button * setBtn;
    Label * realTempLbl;
    Label * wantedTempLbl;
    Label * realTempDesLbl;
    Label * wantedTempDesLbl;

    Label * ramp1Lbl;
    Label * soakTimeLbl;
    Label * soakTempLbl;
    Label * ramp2Lbl;
    Label * reflowTempLbl;
    Label * reflowTimeLbl;

    Button * minRamp1Btn;
    Button * minSoakTimeBtn;
    Button * minSoakTempBtn;
    Button * minRamp2Btn;
    Button * minReflowTempBtn;
    Button * minReflowTimeBtn;

    Label * ramp1ValLbl;
    Label * soakTimeValLbl;
    Label * soakTempValLbl;
    Label * ramp2ValLbl;
    Label * reflowTempValLbl;
    Label * reflowTimeValLbl;

    Button * plusRamp1Btn;
    Button * plusSoakTimeBtn;
    Button * plusSoakTempBtn;
    Button * plusRamp2Btn;
    Button * plusReflowTempBtn;
    Button * plusReflowTimeBtn;


};

#endif
