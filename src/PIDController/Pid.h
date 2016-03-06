#ifndef __PID_H__
#define __PID_H__

class Pid
{
  public:
  Pid();
  void Compute();
  void SetTunings(double Kp, double Ki, double Kd);

  private:
  unsigned long lastTime;
  double input, output, setpoint, errSum, lastErr, kp, ki, kd;
};

#endif
