#include "Temp.h"

Temp::Temp()
{
  //zijn deze lijnen overbodig?
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, INPUT);

  thermocouple = new Adafruit_MAX31855(MAXCLK, MAXCS, MAXDO);
}

double Temp::GetTemperature()
{
  double c = thermocouple->readCelsius();
  return c;

}
