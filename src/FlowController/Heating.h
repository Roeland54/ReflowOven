#ifndef __HEATING_H__
#define __HEATING_H__

#include <arduino.h>

class Heating
{
  public:
    Heating();
    void Start();
    void Stop();
    void SetValue(float value);

  private:

};

#endif
