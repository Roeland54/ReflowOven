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

  private:
  unsigned long lastTime;
  float input, output, setpoint, errSum, lastInput, kp, ki, kd;
  int sampleTime;
};

#endif
