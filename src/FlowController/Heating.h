#ifndef __HEATING_H__
#define __HEATING_H__

#include <arduino.h>
#include "../Config.h"
#include <DueTimer.h>

class Heating
{
  public:
    Heating();
    Heating(CallbackFunctionPointer UpdateZC, CallbackFunctionPointer TrigTriac);
    void Start();
    void Stop();
    void SetValue(int value);
    void UpdateAtZeroCross();
    void TriggerTriac();
  private:

    int value;
    bool trigger;
};

#endif
