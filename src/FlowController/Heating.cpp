#include "Heating.h"

Heating::Heating()
{

}

Heating::Heating(CallbackFunctionPointer UpdateZC, CallbackFunctionPointer TrigTriac)
{
  //Serial.println("create heating");
  pinMode(ZEROCROSSPIN, INPUT);
  pinMode(TOPHEATERPIN, OUTPUT);
  pinMode(BOTTOMHEATERPIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ZEROCROSSPIN), UpdateZC, CHANGE);

  Timer1.attachInterrupt(TrigTriac).start(9000);
  Timer1.stop();

  value = 0;
  trigger = true;
}

void Heating::Start()
{
  Serial.println("start heating");
}

void Heating::Stop()
{
  SetValue(0);
}

void Heating::SetValue(int value)
{
  this->value = value;
}
void Heating::UpdateAtZeroCross()
{
  Serial.println("ZC");
  Timer1.start(-30*value+7800);
}

void Heating::TriggerTriac()
{
  Timer1.stop();

  if(trigger)
  {
    trigger = false;
    digitalWrite(TOPHEATERPIN, HIGH);
    digitalWrite(BOTTOMHEATERPIN, HIGH);
    Serial.println("trigger");
    Timer1.start(100); //Call same function with trigger false to disable triac pin
  }
  else
  {
    trigger = true;
    digitalWrite(TOPHEATERPIN, LOW);
    digitalWrite(BOTTOMHEATERPIN, LOW);
  }
}
