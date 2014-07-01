#ifndef SENSOR_H_
#define SENSOR_H_
#include "Arduino.h"
class Sensor{
  public:
  Sensor(int, int);
  long getDistancia();
  private:
  const int _trig, _echo;
};
#endif
