#ifndef __SERIALCONTROLLER_H__
#define __SERIALCONTROLLER_H__

#include <arduino.h>
#include <CmdMessenger.h>  // CmdMessenger


class SerialController
{
public:
  SerialController();
  void SendTempData(double temp, double setpoint);
  void attachCommandCallBacks();
  void OnReceivePid(CmdMessenger *cmd2);
private:
  CmdMessenger *cmdMessenger;


  enum {Eerste, AReceivePid, StartLogging , Log};
};

#endif
