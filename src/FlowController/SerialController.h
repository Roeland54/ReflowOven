#ifndef __SERIALCONTROLLER_H__
#define __SERIALCONTROLLER_H__

#include <arduino.h>
#include <CmdMessenger.h>  // CmdMessenger

class SerialController
{
public:
  SerialController();
  void SendTempData(int temp, int setpoint);
  void attachCommandCallBacks();
private:
  CmdMessenger *cmdMessenger;

  static void OnReceivePid();
  enum {ASendTempData , AReceivePid};
};

#endif
