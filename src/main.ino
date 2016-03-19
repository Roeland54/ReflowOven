#include "View/ReflowView.h"
#include "FlowController/FlowController.h"
#include "settingClasses/SetupSettings.h"


SetupSettings settings;
// ReflowView view(ILI9341_S5P,11,13,8,9,10);
FlowController controller;

void setup()
{
	controller.Init(&settings);
}

void loop()
{
	delay(1000);
	controller.SendSerialmsg(millis());

}
