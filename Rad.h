#ifndef Rad_H_
#define Rad_H_
#include "PuenteH.h"
#include "Arduino.h"

class Rad
{
  public:
    Rad(const int[cantMotores][pinesPorMotor]);
    void moverRad(PuenteH::Direccion);
    void detenerRad();
    void cambiarVelocidad(int);
    
   private:
    PuenteH puente;
};

#endif
