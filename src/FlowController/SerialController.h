#ifndef __SERIALCONTROLLER_H__
#define __SERIALCONTROLLER_H__

#include <arduino.h>

class SerialController
{
public:
  SerialController();
  void StartSerial();
  void SendMsg(const char *msg);
private:

};

#endif
