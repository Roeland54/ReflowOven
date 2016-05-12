#include "FlowController/Heating.h"
#include "FlowController/Temp.h"
#include "Config.h"
#include <arduino.h>


void UpdateZeroCross(); // methode die zal worden aangeroepen bij iedere nuldoorgang
void TriggerTriac(); //methode om de dimmer te activeren.
CallbackFunctionPointer UpdateZC = &UpdateZeroCross;
CallbackFunctionPointer TrigTriac = &TriggerTriac;
volatile int heatingValue = NULL;

Heating heating;
Temp temp;

void Setup()
{
  Serial.begin(9600);
  Serial.println("start");
  Heating heating(UpdateZC, TrigTriac);
  heating.Start();
  heating.SetValue(255);

  Temp temp();
}

void Loop()
{
  delay(500);
  Serial.println(temp.GetTemperature());
}

void UpdateZeroCross()
{
	heating.UpdateAtZeroCross();
}

void TriggerTriac()
{
	heating.TriggerTriac();
}
