#ifndef __PID_H__
#define __PID_H__

#include <arduino.h>

class Pid
{
  public:
  Pid();
  float Compute();
  void SetTunings(float Kp, float Ki, float Kd);

  private:
  unsigned long lastTime;
  float input, output, setpoint, errSum, lastErr, kp, ki, kd;
};

#endif
