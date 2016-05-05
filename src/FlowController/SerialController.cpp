#include "SerialController.h"

SerialController::SerialController()
{
  Serial.begin(9600);
}

void SerialController::StartSerial()
{
  Serial.println("gestart");
}

void SerialController::SendMsg(const char *msg)
{
  Serial.println(msg);
}
