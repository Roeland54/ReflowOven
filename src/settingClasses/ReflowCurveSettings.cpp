#include "ReflowCurveSettings.h"

ReflowCurveSettings::ReflowCurveSettings()
{
  rtsTempPerSec = 1.5;
  soakTime = 80;
  soakTemp = 150;
  kp = 4;
  ki = 0;
  kd = 0;
  rtpTempPerSec = 2;
  reflowMaxTemp = 230;
  reflowTime = 50;
  coolingTempPerSec = 3;
}

void ReflowCurveSettings::SetPIDTunings(double Kp, double Ki, double Kd)
{
  kp = Kp;
  ki = Ki;
  kd = Kd;
}

void ReflowCurveSettings::SetSoak(double RtsTempPerSec, double SoakTime, int SoakTemp)
{
  rtsTempPerSec = RtsTempPerSec;
  soakTime = SoakTime;
  soakTemp = SoakTemp;
}

void ReflowCurveSettings::SetReflow(double RtpTemPerSec, double ReflowMaxTemp, int ReflowTime)
{
  rtpTempPerSec = RtpTemPerSec;
  reflowMaxTemp = ReflowMaxTemp;
  reflowTime = ReflowTime;
}

void ReflowCurveSettings::SetCooling(double CoolingTempPerSec)
{
  coolingTempPerSec = CoolingTempPerSec;
}
