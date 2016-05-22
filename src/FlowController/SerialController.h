#ifndef __SERIALCONTROLLER_H__
#define __SERIALCONTROLLER_H__

#include <arduino.h>
#include <CmdMessenger.h>  // CmdMessenger
#include "../Config.h"

class SerialController
{
public:
  SerialController();
  SerialController(CallbackFunctionPointer OnRecPid);
  void SendTempData(double temp, double setpoint, double output);
  void attachCommandCallBacks();
  void OnReceivePid();
  long startAcqMillis = 0;
private:
  CmdMessenger *cmdMessenger;
  CallbackFunctionPointer OnRecPid;

  enum {Eerste, AReceivePid, StartLogging , Log};
};

#endif
