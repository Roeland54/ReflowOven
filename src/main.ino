#include "View/ReflowView.h"
#include "FlowController/FlowController.h"
#include "settingClasses/SetupSettings.h"
#include "settingClasses/ReflowCurveSettings.h"
#include "FlowController/Heating.h"
#include <arduino.h>
#include "Config.h"
#include "View/Ui/Widget.h"

//aanmaken van Methodes & functie pointers die noodzakelijk zijn om interrupts te kunnen gebruiken
//alles voor de verwarming:
Heating heating;
void UpdateZeroCross(); // methode die zal worden aangeroepen bij iedere nuldoorgang
void TriggerTriac(); //methode om de dimmer te activeren.
CallbackFunctionPointer UpdateZC = &UpdateZeroCross;
CallbackFunctionPointer TrigTriac = &TriggerTriac;
volatile int heatingValue = NULL;

//alles voor de seriële com
SerialController serialController;
void OnReceivePid();
CallbackFunctionPointer OnRecPid = &OnReceivePid;

//GUI pointers
void pressCallBack(Widget * _widget);
void releaseCallBack(Widget * _widget);
float temp;
ClickedCallbackPointer press = &pressCallBack;
ClickedCallbackPointer release = &releaseCallBack;

// pointers worden meegegeven in de setupsettings
SetupSettings *settings = new SetupSettings(&heating, UpdateZC, TrigTriac, &serialController, OnRecPid, &temp);

FlowController *controller = new FlowController();
ReflowCurveSettings *curveSettings = new ReflowCurveSettings();

ReflowView view;

void pressCallBack(Widget * _widget);
void releaseCallBack(Widget * _widget);

void setup()
{

	Serial.begin(9600);
	view = ReflowView(press, release);

	//controller->Start(curveSettings);


}

void loop()
{

	//controller->Compute();
	view.Update();
	Serial.println("puls");
	delay(100);

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

void pressCallBack(Widget * _widget)
{
	/*
	if(_widget == &onBtn)
	{
		Serial.println("on");
		controller->Start(curveSettings);
	}
	else if(_widget == &offBtn)
	{
		Serial.println("off");
		controller->Stop();
	}
	*/

}

void releaseCallBack(Widget * _widget)
{

}
