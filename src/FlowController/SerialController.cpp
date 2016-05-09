#include "SerialController.h"
#include "Functor.cpp"

long startAcqMillis = 0;

SerialController::SerialController()
{
  Serial.begin(9600);
  cmdMessenger = new CmdMessenger(Serial);
  attachCommandCallBacks();
  cmdMessenger->sendCmd(StartLogging,"Start Logging");
  startAcqMillis = millis();
}

void SerialController::SendTempData(int temp, int setpoint)
{

  float seconds = (float) (millis()-startAcqMillis) /1000.0 ;

  cmdMessenger->sendCmdStart(Log);
  cmdMessenger->sendCmdArg(seconds);
  cmdMessenger->sendCmdArg(temp/10);
  cmdMessenger->sendCmdArg(setpoint/10);
  cmdMessenger->sendCmdEnd();
}


void SerialController::attachCommandCallBacks()
{
  //Functor functor(this);
  //cmdMessenger->attach(AReceivePid, OnReceivePid(cmdMessenger));

}

void SerialController::OnReceivePid(CmdMessenger *cmd2)
{
  Serial.println("ontvangen");
}
