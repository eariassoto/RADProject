#include "PuenteH.h"

PuenteH::PuenteH(const int motorMat[cantMotores][pinesPorMotor])
{
  for(int i=0;i<cantMotores;i++){
    for(int j=0;j<pinesPorMotor;j++){
      
      motor[i][j] = motorMat[i][j];
      pinMode(motor[i][j], OUTPUT);
      digitalWrite(motor[i][j], LOW);
    }
  }
  
  velocidad = 255;
}

void PuenteH::moverMotor(int numeroMotor, Direccion d){
  if(d == ADELANTE){
    digitalWrite(motor[numeroMotor][0], HIGH);
    digitalWrite(motor[numeroMotor][1], LOW);
  }
  else{
    digitalWrite(motor[numeroMotor][0], LOW);
    digitalWrite(motor[numeroMotor][1], HIGH);
  }
  analogWrite(motor[numeroMotor][2], velocidad);
}

void PuenteH::detenerMotores(){
  for(int i=0;i<cantMotores;i++){
    for(int j=0;j<pinesPorMotor;j++){
      digitalWrite(motor[i][j], LOW);
    }
  }
}

void PuenteH::detenerMotor(int m){
  for(int j=0;j<pinesPorMotor;j++){
    digitalWrite(motor[m][j], LOW);
  }
}

void PuenteH::moverMotores(Direccion d){
  switch(d){
    case ADELANTE:
    moverMotor(0, ADELANTE);
    moverMotor(1, ADELANTE);
    break;
    case ATRAS:
    moverMotor(0, ATRAS);
    moverMotor(1, ATRAS);
    break;
    case IZQUIERDA:
    moverMotor(0, ATRAS);
    moverMotor(1, ADELANTE);
    break;
    case DERECHA:
    moverMotor(0, ADELANTE);
    moverMotor(1, ATRAS);
    break;
  }
} 

void PuenteH::cambiarVelocidad(int v){
  velocidad += v;
  if(velocidad > 256){
    velocidad -= v;
  }else if(velocidad <= 0){
    velocidad = 0;
  }
   delay(20);
}
