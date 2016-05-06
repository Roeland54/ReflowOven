#include "FlowController.h"

FlowController::FlowController()
{

}


void FlowController::Init(SetupSettings  *setupSettings)
{
  serialController = new SerialController();
}

void FlowController::Start(ReflowCurveSettings *reflowCurveSettings)
{
  this->reflowCurveSettings = reflowCurveSettings;

  pid = new Pid();
  pid->SetTunings(reflowCurveSettings->kp, reflowCurveSettings->ki, reflowCurveSettings->kd);
  pid->SetSampleTime(100);
  pid->SetOutputLimits(-1000, 1000);
  pid->SetSetpoint(GetTempDataPoint(0));

  currentDataPoint = 0;
  lastTime = 0;

  heating = new Heating();
  heating->Start();

  temp = new Temp();
}

void FlowController::Compute()
{
  int now = millis();
  int currentTemp = temp->GetTemperature();

  if (now - lastTime > 1000)
  {
    currentDataPoint++;
    setpoint = GetTempDataPoint(currentDataPoint);
    pid->SetSetpoint(setpoint);
    //Serial.println("setpoint");
    lastTime = now;
    serialController->SendTempData(currentTemp, setpoint);
  }

  float output = pid->Compute(currentTemp);
  heating->SetValue(output);
  //Serial.println(setpoint);
  //Serial.println(output);

}

int FlowController::GetTempDataPoint(int sec)
{
  int i = 0;
  int y = 0;
  int lastSetPoint = 190;

  //define ramp to soak
  while (lastSetPoint < reflowCurveSettings->soakTemp)
  {
    lastSetPoint += reflowCurveSettings->rtsTempPerSec;
    lastSetPoint;
    if (i == sec)
      return lastSetPoint;
    i++;
  }

  //add soak
  int soakTime = (reflowCurveSettings->soakTime)/10;

  while (y < soakTime)
  {
    lastSetPoint = reflowCurveSettings->soakTemp;
    if (i == sec)
      return lastSetPoint;
    i++;
    y++;

  }

  //Serial.println("2");
  //add ramp to reflow
  while (lastSetPoint < reflowCurveSettings->reflowMaxTemp)
  {
    lastSetPoint += reflowCurveSettings->rtpTempPerSec;
    if (i == sec)
      return lastSetPoint;
    i++;
  }

  //add reflow time
  int reflowTime = (reflowCurveSettings->reflowTime)/10;

  y = 0;
  while (y < reflowTime)
  {
    lastSetPoint = reflowCurveSettings->reflowMaxTemp;
    if (i == sec)
      return lastSetPoint;
    i++;
    y++;
  }

  // Cooling
  while (lastSetPoint > 240)
  {
    lastSetPoint -= reflowCurveSettings->coolingTempPerSec;
    if (i == sec)
      return lastSetPoint;
    i++;
  }

  return i;

}

void FlowController::Stop()
{

}

bool FlowController::GetState()
{

}

int FlowController::GetTemperature()
{

}

void FlowController::SetSettings(SetupSettings *setupSettings)
{

}
