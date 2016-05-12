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

//ReflowView view;
UTFT tft(TFT01_24_16, 38, 39, 40, 41);
UTouch touch( 6, 5, 4, 3, 2);

void pressCallBack(Widget * _widget);
void releaseCallBack(Widget * _widget);
GUI gui(&tft, &touch, &pressCallBack, &releaseCallBack);

char * onTxt = "ON";
char * offTxt = "OFF";
char * tmpLblTxt = "%4.2f C";
Label tmpLbl(new Point(10, 120), tmpLblTxt);
Button onBtn(new Point(10,15), new Size(125,92), onTxt);
Button offBtn(new Point(170,15), new Size(125,92), offTxt);

void setup()
{

	tft.InitLCD();
  tft.clrScr();
  tft.fillScr(VGA_WHITE);

	touch.InitTouch();
	touch.setPrecision(PREC_MEDIUM);

	controller->Init(settings);

  onBtn.setColors(VGA_LIME, VGA_LIME, VGA_GREEN, VGA_WHITE);
	offBtn.setColors(VGA_RED, VGA_RED, VGA_BLACK, VGA_WHITE);
  tmpLbl.setColors(VGA_BLACK, VGA_WHITE, VGA_BLACK, VGA_BLACK);


  tmpLbl.addBinding((void*)&temp, FLOAT);

	gui.addWidget(&onBtn);
	gui.addWidget(&offBtn);
	gui.addWidget(&tmpLbl);

	gui.draw();
	//view = ReflowView(press, release);

	//controller->Start(curveSettings);

	//Serial.begin(9600);
}

void loop()
{

	controller->Compute();
	gui.update();

	//view.Update();
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

void pressCallBack(Widget * _widget)
{
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

}

void releaseCallBack(Widget * _widget)
{

}
