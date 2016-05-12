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
volatile int i = 0;
int y = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("start");
  //heating = Heating(UpdateZC, TrigTriac);
  //heating.Start();
  //heating.SetValue(255);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  temp = Temp();
}

void loop()
{

  Serial.println(temp.GetTemperature());
  //Serial.println(i);
  analogWrite(TOPHEATERPIN, 30);
  analogWrite(BOTTOMHEATERPIN, 30);


}

void UpdateZeroCross()
{
  /*
  delayMicroseconds(150);
  digitalWrite(TOPHEATERPIN, HIGH);
  digitalWrite(BOTTOMHEATERPIN, HIGH);
  delayMicroseconds(100);
  digitalWrite(TOPHEATERPIN, LOW);
  digitalWrite(BOTTOMHEATERPIN, LOW);
  i++;
  */
  //Serial.println(millis());
	//heating.UpdateAtZeroCross();
}

void TriggerTriac()
{
  //Serial.println(millis());
  //Serial.println(".");
	//heating.TriggerTriac();

}
