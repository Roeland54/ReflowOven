#ifndef __PID_H__
#define __PID_H__

#include <arduino.h>

class Pid
{
  public:
  Pid();
  float Compute();
  void SetTunings(float Kp, float Ki, float Kd);
  void SetSampleTime(int NewSampleTime);
  void SetOutputLimits(float Min, float Max);
  
  private:
  unsigned long lastTime;
  float input, output, setpoint, iTerm, lastInput, kp, ki, kd, outMin, outMax;
  int sampleTime;
};

#endif
