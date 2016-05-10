#include "Pid.h"

Pid::Pid()
{
  //Serial.println("create pid");
}

double Pid::Compute(double Input)
{
  input = Input;
  /*How long since we last calculated*/
  unsigned long now = millis();
  int timeChange = (now - lastTime);
  if(timeChange >= sampleTime)
  {
    /*Compute all the working error variables*/
    double error = setpoint - input;
    iTerm += (ki * error);
    if(iTerm > outMax)
      iTerm = outMax;
    else if (iTerm < outMin)
      iTerm = outMin;
    double dInput = input - lastInput;

    /*Compute PID Output*/
    output = kp * error + iTerm - kd * dInput;
    if(output > outMax) output = outMax;
    else if(output < outMin) output = outMin;

    /*Remember some variables for next time*/
    lastInput = input;
    lastTime = now;
  }

  return output;

}

void Pid::SetSampleTime(double newSampleTime)
{
  if (newSampleTime < 0)
  {
    double ratio = (double)newSampleTime/ (double)sampleTime;
    ki *= ratio;
    kd /= ratio;
    sampleTime = (unsigned long)newSampleTime;
  }
}

void Pid::SetTunings(double Kp, double Ki, double Kd)
{
  double sampleTimeInSec = sampleTime/1000;
  kp = Kp;
  ki = Ki * sampleTimeInSec;
  kd = Kd / sampleTimeInSec;

  kp = (0 - kp);
  ki = (0 - ki);
  kd = (0 - kd);
}

void Pid::SetOutputLimits(double Min, double Max)
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

void Pid::SetSetpoint(double Setpoint)
{
  setpoint = Setpoint;
}
