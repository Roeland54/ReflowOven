#include "Pid.h"

Pid::Pid()
{
  sampleTime = 1000;
}

float Pid::Compute()
{
  /*How long since we last calculated*/
  unsigned long now = millis();
  float timeChange = (now - lastTime);
  if(timeChange >= sampleTime)
  {
    /*Compute all the working error variables*/
    float error = setpoint - input;
    errSum += error;
    float dInput = input - lastInput;

    /*Compute PID Output*/
    output = kp * error + ki * errSum - kd * dInput;

    /*Remember some variables for next time*/
    lastInput = input;
    lastTime = now;
  }

  return output;

}

void Pid::SetSampleTime(int newSampleTime)
{
  if (newSampleTime < 0)
  {
    float ratio = (float)newSampleTime/ (float)sampleTime;
    ki *= ratio;
    kd /= ratio;
    sampleTime = (unsigned long)newSampleTime;
  }
}

void Pid::SetTunings(float Kp, float Ki, float Kd)
{
  float sampleTimeInSec = sampleTime/1000;
  kp = Kp;
  ki = Ki * sampleTimeInSec;
  kd = Kd / sampleTimeInSec;
}
