#include "FlowController.h"
#include "../Config.h"

FlowController::FlowController()
{

}

void FlowController::Init(SetupSettings  *setupSettings)
{
  heating = setupSettings->heating;
  heating = new Heating(setupSettings->UpdateZC, setupSettings->TrigTriac);
  serialController = setupSettings->serialController;
  serialController = new SerialController(setupSettings->OnRecPid);
  realTemp = setupSettings->realTemp;
  wantedTemp = setupSettings->wantedTemp;
}

void FlowController::Start(ReflowCurveSettings *reflowCurveSettings)
{
  enable = true;
  currentDataPoint = 0;
  serialController->startAcqMillis = 0;
  this->reflowCurveSettings = reflowCurveSettings;

  pid = Pid();
  pid.SetTunings(reflowCurveSettings->kp, reflowCurveSettings->ki, reflowCurveSettings->kd);
  pid.SetSampleTime(100);
  pid.SetOutputLimits(-255, 255);
  pid.SetSetpoint(GetTempDataPoint(0));

  currentDataPoint = 0;
  lastTime = 0;
  heating->Start();
  temp = Temp();

}

void FlowController::Compute()
{
  if (enable == true)
  {
    int now = millis();
    double currentTemp = temp.GetTemperature();
    *realTemp = currentTemp;

    if (now - lastTime > 1000)
    {
      currentDataPoint++;
      setpoint = GetTempDataPoint(currentDataPoint);
      pid.SetSetpoint(setpoint);
      lastTime = now;

    }

    *wantedTemp = setpoint;
    double output = pid.Compute(currentTemp);
    serialController->SendTempData(currentTemp, setpoint, output);
    heating->SetValue(output);

  }
  else
  {
    if (heating != NULL)
    heating->Stop();
  }
}

double FlowController::GetTempDataPoint(int sec)
{
  int i = 0;
  int y = 0;
  double lastSetPoint = 15;

  //define ramp to soak
  while (lastSetPoint < reflowCurveSettings->soakTemp)
  {
    lastSetPoint += reflowCurveSettings->rtsTempPerSec;
    if (i == sec)
      return lastSetPoint;
    i++;
  }

  //add soak
  int soakTime = (reflowCurveSettings->soakTime);

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
  int reflowTime = (reflowCurveSettings->reflowTime);

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
  while (lastSetPoint > 24)
  {
    lastSetPoint -= reflowCurveSettings->coolingTempPerSec;
    if (i == sec)
      return lastSetPoint;
    i++;
  }

  return 0;

}

void FlowController::Stop()
{
  enable = false;
  heating->Stop();
}

bool FlowController::GetState()
{
  return enable;
}

double FlowController::GetTemperature()
{
  return temp.GetTemperature();
}

void FlowController::SetSettings(SetupSettings *setupSettings)
{

}
