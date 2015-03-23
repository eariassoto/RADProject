#ifndef PuenteH_H_
#define PuenteH_H_
#define cantMotores 2
#define pinesPorMotor 3
// este codigo es compatible con puentes H para dos motores
// por ejemplo el L298N H-Bridge Motor Driver Shield MotoMama
#include "Arduino.h"

class PuenteH
{
  public:
    PuenteH(const int[cantMotores][pinesPorMotor]);
    
    // modos de movimientos de los motores
    enum Direccion {
      ADELANTE,
      ATRAS,
      IZQUIERDA,
      DERECHA
    };
    void moverMotores(Direccion);
    void detenerMotores();
    
    void moverMotor(int, Direccion); // donde int corresponde al numero del motor
    void detenerMotor(int);
    
    void cambiarVelocidad(int);
    
  private:
    int motor[cantMotores][pinesPorMotor];
    int  velocidad;
};

#endif
