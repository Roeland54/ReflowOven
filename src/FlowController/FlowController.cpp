#include "FlowController.h"

FlowController::FlowController(SetupSettings  *setupSettings)
{

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
  Serial.println(boodschap);
}
