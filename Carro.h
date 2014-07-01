#ifndef CARRO_H_
#define CARRO_H_
#include "Sensor.h"
#include "Arduino.h"

class Carro
{
  public:
    Carro(int, int, int, int, int, int, int, int, int, int);
    void detener();
    void adelante();
    void atras();
    void girarDerecha();
    void girarIzquierda();
    void apagarTodo();
    void encender(int);
    void cambiarVelocidad(int);
    int  velocidad;
    
  private:
    const int _inA1, _inA2, _enA, _inB1, _inB2, _enB, _ledAd, _ledAt, _ledDer, _ledIzq;
    int  estadoLedDer, estadoLedIzq;
    
    long previousMillis, interval, currentMillis;
    void moverA(bool);
    void moverB(bool);
    void moverJuntos(bool);
    void moverInversos(bool);
    void encenderDireccional(int);
};

#endif
