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

  //attachInterrupt(digitalPinToInterrupt(ZEROCROSSPIN), UpdateZC, CHANGE);

  Timer1.attachInterrupt(TrigTriac).start(9000);
  Timer1.stop();

  enable = false;
  heatingValue = 0;
  trigger = true;
}

void Heating::Start()
{
  enable = true;
}

void Heating::Stop()
{
  enable = false;
  SetValue(0);
}

void Heating::SetValue(int value)
{
  if (enable && value > 0)
  {

    //heatingValue = value;
    //Serial.println(heatingValue);
    analogWrite(TOPHEATERPIN, value);
    analogWrite(BOTTOMHEATERPIN, value);
  }
  else
  {
    //heatingValue = 0;
    analogWrite(TOPHEATERPIN, 0);
    analogWrite(BOTTOMHEATERPIN, 0);
  }
}
void Heating::UpdateAtZeroCross()
{
  //Serial.println("ZC");
  int x = -30 * heatingValue +7800;
  Timer1.start(x);
  //Serial.println(x);
}

void Heating::TriggerTriac()
{
  Timer1.stop();

  if(trigger)
  {
    trigger = false;
    digitalWrite(TOPHEATERPIN, HIGH);
    digitalWrite(BOTTOMHEATERPIN, HIGH);
    //Serial.println(millis());
    //Serial.println("trigger");
    Timer1.start(100); //Call same function with trigger false to disable triac pin
  }
  else
  {
    trigger = true;
    digitalWrite(TOPHEATERPIN, LOW);
    digitalWrite(BOTTOMHEATERPIN, LOW);
  }

}
