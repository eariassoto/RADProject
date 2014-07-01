#include "Sensor.h"
Sensor::Sensor(int trig, int echo):
_trig(trig), _echo(echo)
{
  pinMode(_trig, OUTPUT);
  pinMode(_echo, INPUT);
}

long Sensor::getDistancia(){
  long duracion, distancia;
  digitalWrite(_trig, LOW);  
  delayMicroseconds(2); 
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(_trig, LOW);
  duracion = pulseIn(_echo, HIGH);
  distancia = (duracion/2) / 29.1;
  return distancia;
}
