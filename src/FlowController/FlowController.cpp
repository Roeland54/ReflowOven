#include "FlowController.h"

FlowController::FlowController()
{

}

void FlowController::Init(SetupSettings  *setupSettings)
{
  Serial.begin(9600);
  Serial.println("test");
  /*
  SerialController serialController;
  serialController.StartSerial();
  */
}

void FlowController::Start(ReflowCurveSettings *reflowCurveSettings)
{
  SendSerialmsg("Flowcontroller Start funct");
  ConvertCurveToArray(reflowCurveSettings);
}

void FlowController::ConvertCurveToArray(ReflowCurveSettings *reflowCurveSettings)
{

  SendSerialmsg("ConvertCurveToArray aanroep");
  /*
  int i = 0;
  int y = 0;
  double lastSetPoint = 18;

  //define ramp to soak
  while (lastSetPoint < reflowCurveSettings->soakTemp)
  {
    curve[i] = lastSetPoint + reflowCurveSettings->rtsTempPerSec;
    lastSetPoint = curve[i];
    i++;
  }

  //add soak
  while (y <= reflowCurveSettings->soakTime)
  {
    curve[i] = reflowCurveSettings->soakTemp;
    Serial.println(curve[i]);
    i++;
    y++;
  }
*/
  //Serial.println("end ConvertCurveToArray");
}

void FlowController::Stop()
{

}

bool FlowController::GetState()
{

}

float FlowController::GetTemperature()
{

}

void FlowController::SetSettings(SetupSettings *setupSettings)
{

}

void FlowController::SendSerialmsg(const char *boodschap)
{
  serialController.SendMsg(boodschap);
}
