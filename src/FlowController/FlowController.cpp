#include "FlowController.h"

FlowController::FlowController()
{

}

void FlowController::Init(SetupSettings  *setupSettings)
{
  SerialController serialController;
  serialController.StartSerial();
}

void FlowController::Start(ReflowCurveSettings *reflowCurveSettings)
{

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

void FlowController::SendSerialmsg(int boodschap)
{
  serialController.SendMsg(boodschap);
}
