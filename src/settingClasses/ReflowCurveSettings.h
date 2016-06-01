#ifndef __REFLOWCURVESETTINGS_H__
#define __REFLOWCURVESETTINGS_H__

class ReflowCurveSettings
{
  public:
    ReflowCurveSettings();
    void SetPIDTunings(double Kp, double Ki, double Kd);
    void SetSoak(double RtsTemPerSec, double SoakTime, double SoakTemp);
    void SetReflow(double RtpTempPerSec, double ReflowMaxTemp, double ReflowTime);
    void SetCooling(double CoolingTempPerSec);


    double kp, ki, kd;
    double rtsTempPerSec, soakTemp, rtpTempPerSec, reflowMaxTemp, coolingTempPerSec;
    double soakTime, reflowTime;
};

#endif
