#include "ReflowCurveSettings.h"

ReflowCurveSettings::ReflowCurveSettings()
{

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
