#include "Carro.h"
Carro::Carro(int ia1, int ia2, int ena, int enb, int inb1, int inb2)
:_inA1(ia1), _inA2(ia2), _enA(ena), _inB1(inb1), _inB2(inb2), _enB(enb)
{
  pinMode(_inA1, OUTPUT);
  pinMode(_inA2, OUTPUT);
  pinMode(_enA, OUTPUT);
  pinMode(_inB1, OUTPUT);
  pinMode(_inB2, OUTPUT);
  pinMode(_enB, OUTPUT);
  
  digitalWrite(_inA1, LOW);
  digitalWrite(_inA2, LOW);
  digitalWrite(_enA, LOW);
  digitalWrite(_inB1, LOW);
  digitalWrite(_inB2, LOW);
  digitalWrite(_enB, LOW);
  
  velocidad = 255;
}

void Carro::moverA(bool d){
  analogWrite(_enA, velocidad);
  if(d){
    digitalWrite(_inA1, HIGH);
    digitalWrite(_inA2, LOW);
  }
  else{
    digitalWrite(_inA2, HIGH);
    digitalWrite(_inA1, LOW);
  }
}

void Carro::moverB(bool d){
  analogWrite(_enB, velocidad);
  if(d){
    digitalWrite(_inB1, HIGH);
    digitalWrite(_inB2, LOW);
  }
  else{
    digitalWrite(_inB2, HIGH);
    digitalWrite(_inB1, LOW);
  }
}

void Carro::detener(){
  digitalWrite(_inA1, LOW);
  digitalWrite(_inA2, LOW);
  digitalWrite(_enA, LOW);
  digitalWrite(_inB1, LOW);
  digitalWrite(_inB2, LOW);
  digitalWrite(_enB, LOW);
}

void Carro::moverJuntos(bool b){
  moverA(b);
  moverB(b);
}

void Carro::moverInversos(bool b){
  moverA(b);
  moverB(!b);
}

void Carro::adelante(){
    moverJuntos(true); 
}

void Carro::atras(){
  moverJuntos(false);
}

void Carro::girarDerecha(){
  moverInversos(true);
}

void Carro::girarIzquierda(){
  moverInversos(false);
}

void Carro::cambiarVelocidad(int v){
  velocidad += v;
  if(velocidad > 256){
    velocidad -= v;
  }else if(velocidad <= 0){
    velocidad = 0;
  }
   delay(20);
}
