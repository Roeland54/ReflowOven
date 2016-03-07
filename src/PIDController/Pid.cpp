#include "Pid.h"

Pid::Pid()
{

}

float Pid::Compute()
{
  /*How long since we last calculated*/
  unsigned long now = millis();
  float timeChange = (float)(now - lastTime);

  /*Compute all the working error variables*/
  float error = setpoint - input;
  errSum += (error * timeChange);
  float dErr = (error - lastErr) / timeChange;

  /*Compute PID Output*/
  output = kp * error + ki * errSum + kd * dErr;

  /*Remember some variables for next time*/
  lastErr = error;
  lastTime = now;

  return output;
}

void Pid::SetTunings(float Kp, float Ki, float Kd)
{
  kp = Kp;
  ki = Ki;
  kd = Kd;
}
