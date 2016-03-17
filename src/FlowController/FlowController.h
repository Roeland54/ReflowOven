#ifndef __FLOWCONTROLLER_H__
#define __FLOWCONTROLLER_H__

#include "../settingClasses/ReflowCurveSettings.h"

class FlowController
{
  public:
  FlowController();
  void Start(ReflowCurveSettings reflowCurveSettings);
  void Stop();
  bool GetState();
  float GetTemperature();

  private:
  bool state;

};

#endif
