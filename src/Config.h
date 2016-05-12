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
#define ZEROCROSSPIN 11
#define BOTTOMHEATERPIN 9
#define TOPHEATERPIN 10

//TFT pins
#define MODEL TFT01_24_16
#define RS 38
#define WR 39
#define CSS 40
#define RST 41

//Touch pins
#define A 6
#define B 5
#define C 4
#define D 3
#define E 2

//
typedef void (*CallbackFunctionPointer)();

//#ifndef __CONFIG_H__
//#define __CONFIG_H__

extern volatile int heatingValue;

//#endif
