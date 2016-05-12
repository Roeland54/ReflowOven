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
}

void FlowController::Start(ReflowCurveSettings *reflowCurveSettings)
{
  enable = true;

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
    //Serial.println(currentTemp);

    if (now - lastTime > 1000)
    {
      currentDataPoint++;
      setpoint = GetTempDataPoint(currentDataPoint);

      //pid.SetSetpoint(150);
      pid.SetSetpoint(setpoint);
      //Serial.println(setpoint);
      lastTime = now;

    }
    Serial.println("");
    //Serial.println(currentTemp);
    double output = pid.Compute(currentTemp);
    serialController->SendTempData(currentTemp, setpoint, output);
    //Serial.println(output);
    //heating->SetValue(output);
    heating->SetValue(output);
    //Serial.println(heating->value);
  }
  else
  {
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
  heating->Stop();
  enable = false;
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
