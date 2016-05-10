#ifndef __PID_H__
#define __PID_H__

#include <arduino.h>

class Pid
{
  public:
    Pid();
    double Compute(double Input);
    void SetSetpoint(double Setpoint);
    void SetTunings(double Kp, double Ki, double Kd);
    void SetSampleTime(double NewSampleTime);
    void SetOutputLimits(double Min, double Max);

  private:
    unsigned long lastTime;
    double input, output, setpoint, iTerm, lastInput, kp, ki, kd, outMin, outMax;
    int sampleTime;
};

#endif
