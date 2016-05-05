#include "ReflowCurveSettings.h"

ReflowCurveSettings::ReflowCurveSettings()
{
  rtsTempPerSec = 30;
  soakTime = 100;
  soakTemp = 1500;
  kp = 2;
  ki = 0;
  kd = 0;
  rtpTempPerSec = 10;
  reflowMaxTemp = 2000;
  reflowTime = 100;
  coolingTempPerSec = 20;
}

void ReflowCurveSettings::SetPIDTunings(int Kp, int Ki, int Kd)
{
  kp = Kp;
  ki = Ki;
  kd = Kd;
}

void ReflowCurveSettings::SetSoak(int RtsTempPerSec, int SoakTime, int SoakTemp)
{
  rtsTempPerSec = RtsTempPerSec;
  soakTime = SoakTime;
  soakTemp = SoakTemp;
}

void ReflowCurveSettings::SetReflow(int RtpTemPerSec, int ReflowMaxTemp, int ReflowTime)
{
  rtpTempPerSec = RtpTemPerSec;
  reflowMaxTemp = ReflowMaxTemp;
  reflowTime = ReflowTime;
}

void ReflowCurveSettings::SetCooling(int CoolingTempPerSec)
{
  coolingTempPerSec = CoolingTempPerSec;
}
