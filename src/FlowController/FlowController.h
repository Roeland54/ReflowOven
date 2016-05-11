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
    void Compute();

    bool GetState();

    double GetTemperature();
    double GetTempDataPoint(int sec);


private:
    int lastTime;
    double setpoint;
    int currentDataPoint;

    bool state;
    bool enable;

    Pid pid;
    Heating *heating;
    Temp temp;
    ReflowCurveSettings *reflowCurveSettings;
    SerialController *serialController;
};

#endif
