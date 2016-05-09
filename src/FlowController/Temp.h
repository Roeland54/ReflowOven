#ifndef __TEMP_H__
#define __TEMP_H__

#include <arduino.h>

class Temp
{
  public:
    Temp();
    float GetTemperature();

  private:
    float temperature;
};

#endif
