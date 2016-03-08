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
    iTerm += (ki * error);
    if(iTerm > outMax)
      iTerm = outMax;
    else if (iTerm < outMin)
      iTerm = outMin;
    float dInput = input - lastInput;

    /*Compute PID Output*/
    output = kp * error + iTerm - kd * dInput;

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

void Pid::SetOutputLimits(float Min, float Max)
{
  if (Min > Max)
    return;
  outMin = Min;
  outMax = Max;

  if(output > outMax)
    output = outMax;
  else if (output < outMin)
    output = outMin;

  if(iTerm > outMax)
    iTerm = outMax;
  else if (iTerm < outMin)
    iTerm = outMin;
}
