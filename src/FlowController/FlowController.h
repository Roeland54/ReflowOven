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
    void SetSettings(SetupSettings  *setupSettings);
    void SendSerialmsg(const char *boodschap);
    void Compute();

    bool GetState();

    int GetTemperature();
    int GetTempDataPoint(int sec);


private:
    int lastTime;
    int setpoint;
    int currentDataPoint;

    bool state;
    
    Pid *pid;
    Heating *heating;
    Temp *temp;
    ReflowCurveSettings *reflowCurveSettings;
    SerialController *serialController;
};

#endif
