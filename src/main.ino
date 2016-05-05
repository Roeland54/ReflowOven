//#include "View/ReflowView.h"
#include "FlowController/FlowController.h"
#include "settingClasses/SetupSettings.h"
#include "settingClasses/ReflowCurveSettings.h"

SetupSettings settings;
// ReflowView view(ILI9341_S5P,11,13,8,9,10);
FlowController controller;
//ReflowCurveSettings curveSettings;

void setup()
{
	controller.Init(&settings);
	//controller.Start(&curveSettings);

}

void loop()
{

}
