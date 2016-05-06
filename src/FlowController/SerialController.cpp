#include "SerialController.h"

SerialController::SerialController()
{
  Serial.begin(9600);
  cmdMessenger = new CmdMessenger(Serial);
  attachCommandCallBacks();
}

void SerialController::SendTempData(int temp, int setpoint)
{
  cmdMessenger->sendCmdStart(ASendTempData);
  cmdMessenger->sendCmdArg(temp);
  cmdMessenger->sendCmdArg(setpoint);
  cmdMessenger->sendCmdEnd();
}


void SerialController::attachCommandCallBacks()
{

  cmdMessenger->attach(AReceivePid, OnReceivePid);

}

void SerialController::OnReceivePid()
{
  Serial.println("ontvangen");
}
