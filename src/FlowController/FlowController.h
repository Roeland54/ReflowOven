#ifndef __FLOWCONTROLLER_H__
#define __FLOWCONTROLLER_H__

#include "../settingClasses/ReflowCurveSettings.h"
#include "../settingClasses/SetupSettings.h"
#include "Cooling.h"
#include "Heating.h"
#include "Pid.h"
#include "SerialController.h"
#include "Temp.h"
#include <arduino.h>

class FlowController
{
public:
    FlowController();
    void Init(SetupSettings  *setupSettings);
    void Start(ReflowCurveSettings *reflowCurveSettings);
    void Stop();
    bool GetState();
    float GetTemperature();
    void SetSettings(SetupSettings  *setupSettings);
    void SendSerialmsg(int boodschap);
private:
    bool state;
    SerialController serialController;
};

#endif
