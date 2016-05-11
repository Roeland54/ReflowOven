#include "View/ReflowView.h"
#include "FlowController/FlowController.h"
#include "settingClasses/SetupSettings.h"
#include "settingClasses/ReflowCurveSettings.h"
#include "FlowController/Heating.h"
#include <arduino.h>
#include "Config.h"

//aanmaken van Methodes & functie pointers die noodzakelijk zijn om interrupts te kunnen gebruiken
//alles voor de verwarming:
Heating heating;
void UpdateZeroCross(); // methode die zal worden aangeroepen bij iedere nuldoorgang
void TriggerTriac(); //methode om de dimmer te activeren.
CallbackFunctionPointer UpdateZC = &UpdateZeroCross;
CallbackFunctionPointer TrigTriac = &TriggerTriac;

//alles voor de seriële com
SerialController serialController;
void OnReceivePid();
CallbackFunctionPointer OnRecPid = &OnReceivePid;

// pointers worden meegegeven in de setupsettings
SetupSettings *settings = new SetupSettings(&heating, UpdateZC, TrigTriac, &serialController, OnRecPid);

//ReflowView view(ILI9341_S5P,11,13,8,9,10);
FlowController *controller = new FlowController();
ReflowCurveSettings *curveSettings = new ReflowCurveSettings();


void setup()
{

	controller->Init(settings);
	controller->Start(curveSettings);

	Serial.begin(9600);
}

void loop()
{

	controller->Compute();
	//Serial.println("puls");
	delay(1000);

}

/*
functie voor UNO
int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
*/
void UpdateZeroCross()
{
	heating.UpdateAtZeroCross();
}

void TriggerTriac()
{
	heating.TriggerTriac();
}

void OnReceivePid()
{
	serialController.OnReceivePid();
}
