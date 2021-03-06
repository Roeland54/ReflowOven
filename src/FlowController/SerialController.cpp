#include "SerialController.h"
#include "Functor.cpp"


SerialController::SerialController()
{

}

SerialController::SerialController(CallbackFunctionPointer OnRecPid)
{
  this->OnRecPid = OnRecPid;
  Serial.begin(9600);
  cmdMessenger = new CmdMessenger(Serial);
  attachCommandCallBacks();
  cmdMessenger->sendCmd(StartLogging,"Start Logging");
  startAcqMillis = 0;
}

void SerialController::SendTempData(double temp, double setpoint, double output)
{
  if (startAcqMillis == 0)
  startAcqMillis = millis();

  int seconds = (int) (millis()-startAcqMillis) /1000.0 ;

  cmdMessenger->sendCmdStart(Log);
  cmdMessenger->sendCmdArg(seconds);
  cmdMessenger->sendCmdArg(temp);
  cmdMessenger->sendCmdArg(setpoint);
  cmdMessenger->sendCmdArg(output);
  cmdMessenger->sendCmdEnd();
}


void SerialController::attachCommandCallBacks()
{
  cmdMessenger->attach(AReceivePid, OnRecPid);
}

void SerialController::OnReceivePid()
{
  cmdMessenger->readDoubleArg();
}
