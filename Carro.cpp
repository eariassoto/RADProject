#include "Carro.h"
Carro::Carro(int ia1, int ia2, int ena, int enb, int inb1, int inb2, int lAd, int lAt, int lDer, int lIzq)
:_inA1(ia1), _inA2(ia2), _enA(ena), _inB1(inb1), _inB2(inb2), _enB(enb), _ledAd(lAd), _ledAt(lAt), _ledDer(lDer), _ledIzq(lIzq)
{
  pinMode(_inA1, OUTPUT);
  pinMode(_inA2, OUTPUT);
  pinMode(_enA, OUTPUT);
  pinMode(_inB1, OUTPUT);
  pinMode(_inB2, OUTPUT);
  pinMode(_enB, OUTPUT);
  pinMode(_ledAd, OUTPUT);
  pinMode(_ledAt, OUTPUT);
  pinMode(_ledIzq, OUTPUT);
  pinMode(_ledDer, OUTPUT);
  
  digitalWrite(_inA1, LOW);
  digitalWrite(_inA2, LOW);
  digitalWrite(_enA, LOW);
  digitalWrite(_inB1, LOW);
  digitalWrite(_inB2, LOW);
  digitalWrite(_enB, LOW);
  digitalWrite(_ledAd, LOW);
  digitalWrite(_ledAt, LOW);
  digitalWrite(_ledDer, LOW);
  digitalWrite(_ledIzq, LOW);
  
  estadoLedDer = LOW;
  estadoLedIzq = LOW;
  
  currentMillis = 0;
  previousMillis = 0;
  interval = 250;
  velocidad = 2;
}

void Carro::apagarTodo(){
  digitalWrite(_ledAd, LOW);
  digitalWrite(_ledAt, LOW);
  digitalWrite(_ledDer, LOW);
  digitalWrite(_ledIzq, LOW);
}

void Carro::encender(int led){
  apagarTodo();
  switch(led){
    case 0:
    digitalWrite(_ledAd, HIGH);
    break;
    case 1:
    digitalWrite(_ledAt, HIGH);
    break;
  }
}

void Carro::moverA(bool d){
  if(d){
    digitalWrite(_inA1, HIGH);
    digitalWrite(_inA2, LOW);
  }
  else{
    digitalWrite(_inA2, HIGH);
    digitalWrite(_inA1, LOW);
  }
  analogWrite(_enA, 25);
}

void Carro::moverB(bool d){
  if(d){
    digitalWrite(_inB1, HIGH);
    digitalWrite(_inB2, LOW);
  }
  else{
    digitalWrite(_inB2, HIGH);
    digitalWrite(_inB1, LOW);
  }
  analogWrite(_enB, 25);
}

void Carro::detener(){
  apagarTodo();
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
    encender(0);
    moverJuntos(true); 
}

void Carro::atras(){
  encender(1);
  moverJuntos(false);
}

void Carro::girarDerecha(){
  apagarTodo();
  encenderDireccional(0);
  moverInversos(true);
}

void Carro::girarIzquierda(){
  apagarTodo();
  encenderDireccional(1);
  moverInversos(false);
}

void Carro::encenderDireccional(int n){
  int led;
  int estado;
  if(n == 0){
    led = _ledDer;
    estado = estadoLedDer;
  }else{
    led = _ledIzq;
    estado = estadoLedIzq; 
  }
  currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;   
    if (estado == LOW)
      estado = HIGH;
    digitalWrite(led, estado);
  }
}

void Carro::cambiarVelocidad(int v){
  velocidad += v;
  if(velocidad > 256){
    velocidad -= v;
  }else if(velocidad <= 0){
    velocidad = 0;
  }
  if(v > 0){
    encender(0);
  }else{
    encender(1);
  }
   delay(20);
   apagarTodo();
}
