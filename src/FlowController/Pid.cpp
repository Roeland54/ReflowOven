#include "Pid.h"

Pid::Pid()
{
  //Serial.println("create pid");
  kp = 0;
  ki = 0;
  kd = 0;

  lastTime = 0;
  lastInput = 0;
  iTerm = 0;
  sampleTime = 100;
  outMax = 255;
  outMin = -255;
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
    /*
    Serial.println(iTerm);
    Serial.println(error);
    Serial.println(ki);
    Serial.print("");
    */
    iTerm += (ki * error);

    if(iTerm > outMax)
      iTerm = outMax;
    else if (iTerm < outMin)
      iTerm = outMin;
    double dInput = input - lastInput;
    //Serial.println(input);
    //Serial.println(lastInput);

    /*Compute PID Output*/

    output = kp * error + iTerm - kd * dInput;

    //Serial.println(kp);
    //Serial.println(error);
    //Serial.println(ki);
    //Serial.println(kd);
    //Serial.println(dInput);
    //Serial.println(output);

    if(output > outMax) output = outMax;
    else if(output < outMin) output = outMin;

    //Serial.println(output);
        //Serial.println("");
    /*Remember some variables for next time*/
    lastInput = input;
    lastTime = now;
  }

  return output;

}

void Pid::SetSampleTime(double newSampleTime)
{
  if (newSampleTime > 0)
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
  if (ki > 0 && ki < 1000)
  ki = Ki * sampleTimeInSec;
  if (kd != 0)
  kd = Kd / sampleTimeInSec;
/*
  Serial.println(kp);
  Serial.println(ki);
  Serial.println(kd);
  */
  //kp = (0 - kp);
  //ki = (0 - ki);
  //kd = (0 - kd);
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
