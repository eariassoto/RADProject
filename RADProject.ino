#include "Rad.h"

const int matMotor[cantMotores][pinesPorMotor] = {{8,9,10},{11,12,13}};
Rad rad(matMotor);

byte incomingByte; 

void interpretarComando(char c)
{
  if (c == 'a') {
      // Nota PuenteH:: significa que estoy haciendo acceso a 
      // un elemento definido en PuenteH.h
      digitalWrite(2, HIGH);
      rad.moverRad(PuenteH::ADELANTE);
    } else if (c == 'b') {
      digitalWrite(2, LOW);
      rad.moverRad(PuenteH::ATRAS);
    }else if (c == 'c') {
      rad.moverRad(PuenteH::DERECHA);
    } else if (c == 'd') {
      rad.moverRad(PuenteH::IZQUIERDA);
    } else if(c == 'e'){
      rad.cambiarVelocidad(20);
    } else if(c == 'f'){
      rad.cambiarVelocidad(-20);
    }else if(c == 'g'){
      delay(500);
    }
    else {
      rad.detenerRad();
    }
}

void setup()
{ 
  Serial.begin(9600);
  digitalWrite(13, LOW);
  incomingByte = 0;
  char str[6] = {'a', 'g', 'b', 'g', 'h', 'g'};
  for(int i = 0; i<6;i++){
    interpretarComando(str[i]);
  }
}

void loop()
{
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    interpretarComando(incomingByte);
  } 
}
