#include "ReflowCurveSettings.h"

ReflowCurveSettings::ReflowCurveSettings()
{
  rtsTempPerSec = 0.5;
  soakTime = 20;
  soakTemp = 130;
  kp = 50;
  ki = 4.5;
  kd = 70;
  rtpTempPerSec = 0.5;
  reflowMaxTemp = 160;
  reflowTime = 20;
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
