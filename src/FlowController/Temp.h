#ifndef __TEMP_H__
#define __TEMP_H__

#include <arduino.h>
#include <SPI.h>
#include "Adafruit_MAX31855.h"
#include "../Config.h"

class Temp
{
  public:
    Temp();
    double GetTemperature();

  private:
    double temperature;
    Adafruit_MAX31855 * thermocouple;

};

#endif
