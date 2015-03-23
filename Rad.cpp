#include "Rad.h"
Rad::Rad(const int motorMat[cantMotores][pinesPorMotor]):puente(motorMat)
{
}

void Rad::detenerRad(){
  puente.detenerMotores();
}

void Rad::moverRad(PuenteH::Direccion d){
  puente.moverMotores(d);
} 

void Rad::cambiarVelocidad(int v){
  puente.cambiarVelocidad(v);
}
