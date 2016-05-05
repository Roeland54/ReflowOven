#ifndef __REFLOWCURVESETTINGS_H__
#define __REFLOWCURVESETTINGS_H__

class ReflowCurveSettings
{
  public:
    ReflowCurveSettings();
    void SetPIDTunings(int Kp, int Ki, int Kd);
    void SetSoak(int RtsTemPerSec, int SoakTime, int SoakTemp);
    void SetReflow(int RtpTempPerSec, int ReflowMaxTemp, int ReflowTime);
    void SetCooling(int CoolingTempPerSec);

  //private:
    int kp, ki, kd;
    int rtsTempPerSec, soakTemp, rtpTempPerSec, reflowMaxTemp, coolingTempPerSec;
    int soakTime, reflowTime;
};

#endif
