#ifndef __REFLOWCURVESETTINGS_H__
#define __REFLOWCURVESETTINGS_H__

class ReflowCurveSettings
{
  public:
    ReflowCurveSettings();
    void SetPIDTunings(double Kp, double Ki, double Kd);
    void SetSoak(double RtsTemPerSec, double SoakTime, int SoakTemp);
    void SetReflow(double RtpTempPerSec, double ReflowMaxTemp, int ReflowTime);
    void SetCooling(double CoolingTempPerSec);

  private:
    double kp, ki, kd;
    double rtsTempPerSec, soakTemp, rtpTempPerSec, reflowMaxTemp, coolingTempPerSec;
    int soakTime, reflowTime;
};

#endif
