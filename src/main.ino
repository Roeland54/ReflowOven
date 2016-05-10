#include "View/ReflowView.h"
#include "FlowController/FlowController.h"
#include "settingClasses/SetupSettings.h"
#include "settingClasses/ReflowCurveSettings.h"


SetupSettings *settings = new SetupSettings();
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
	//Serial.println(freeRam());
	delay(1000);

}


int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
