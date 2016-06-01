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
float wantedTemp = 200;
float realTemp = 10;
ClickedCallbackPointer press = &pressCallBack;
ClickedCallbackPointer release = &releaseCallBack;

// pointers worden meegegeven in de setupsettings
SetupSettings *settings = new SetupSettings(
	&heating,
	UpdateZC,
	TrigTriac,
	&serialController,
	OnRecPid,
	&wantedTemp,
	&realTemp);

FlowController *controller = new FlowController();
ReflowCurveSettings *curveSettings = new ReflowCurveSettings();

ReflowView view;

void pressCallBack(Widget * _widget);
void releaseCallBack(Widget * _widget);

int i = 0;

void setup()
{
	view = ReflowView(press, release, &wantedTemp, &realTemp, curveSettings);
	controller->Init(settings);
  Serial.println("start");
}

void loop()
{

	controller->Compute();
	view.Update();
	delay(100);

}

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
	if (_widget->text == "START")
	{
		controller->Start(curveSettings);
	}
	else if (_widget->text == "STOP")
	{
		controller->Stop();
	}
	view.pressCallBack(_widget);
}

void releaseCallBack(Widget * _widget)
{
	view.releaseCallBack(_widget);
}
