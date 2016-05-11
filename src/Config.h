/*
#include "View/ReflowView.h"
#include "FlowController/FlowController.h"
#include "settingClasses/SetupSettings.h"
#include "settingClasses/ReflowCurveSettings.h"
#include "FlowController/Heating.h"
#include <arduino.h>
*/
#include <CmdMessenger.h>
#include "FlowController/SerialController.h"


// MAX31855 pins
#define MAXDO   18
#define MAXCS   17
#define MAXCLK  16

//Heating pins
#define ZEROCROSSPIN 8
#define BOTTOMHEATERPIN 9
#define TOPHEATERPIN 10

//
typedef void (*CallbackFunctionPointer)();
