#include "ReflowCurveSettings.h"

ReflowCurveSettings::ReflowCurveSettings()
{
  rtsTempPerSec = 3;
  soakTime = 10;
  soakTemp = 150;
  kp = 2;
  ki = 0;
  kd = 0;
  rtpTempPerSec = 1;
  reflowMaxTemp = 200;
  reflowTime = 10;
  coolingTempPerSec = 2;
}

void ReflowCurveSettings::SetPIDTunings(double Kp, double Ki, double Kd)
{
  kp = Kp;
  ki = Ki;
  kd = Kd;
}

void ReflowCurveSettings::SetSoak(double RtsTempPerSec, double SoakTime, double SoakTemp)
{
  rtsTempPerSec = RtsTempPerSec;
  soakTime = SoakTime;
  soakTemp = SoakTemp;
}

void ReflowCurveSettings::SetReflow(double RtpTemPerSec, double ReflowMaxTemp, double ReflowTime)
{
  rtpTempPerSec = RtpTemPerSec;
  reflowMaxTemp = ReflowMaxTemp;
  reflowTime = ReflowTime;
}

void ReflowCurveSettings::SetCooling(double CoolingTempPerSec)
{
  coolingTempPerSec = CoolingTempPerSec;
}
