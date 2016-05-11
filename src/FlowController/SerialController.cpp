#include "SerialController.h"
#include "Functor.cpp"

long startAcqMillis = 0;

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
  startAcqMillis = millis();
}

void SerialController::SendTempData(double temp, double setpoint)
{

  int seconds = (int) (millis()-startAcqMillis) /1000.0 ;

  cmdMessenger->sendCmdStart(Log);
  cmdMessenger->sendCmdArg(seconds);
  cmdMessenger->sendCmdArg(temp);
  cmdMessenger->sendCmdArg(setpoint);
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
