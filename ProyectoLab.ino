#include "Carro.h"
#include "Sensor.h"

Carro carro(8,9,10,11,12,13, 2, 3, 5, 4);
Sensor sensor(6, 7);

byte incomingByte; 
void setup(){
  Serial.begin(9600);
  digitalWrite(13, LOW);
  incomingByte = 0;
 
}
void loop(){
  if (Serial.available() > 0) {
  incomingByte = Serial.read();
  Serial.println(incomingByte);
  Serial.flush(); 
  }   
  if(sensor.getDistancia() > 10){
    if (incomingByte == 97) {
      digitalWrite(2, HIGH);
      carro.adelante();
    } else if (incomingByte == 'b') {
      digitalWrite(2, LOW);
      carro.atras();
    }else if (incomingByte == 'c') {
      carro.girarDerecha();
    } else if (incomingByte == 'd') {
      carro.girarIzquierda();
    } else if(incomingByte == 'e'){
      Serial.println(carro.velocidad);
      carro.cambiarVelocidad(20);
    } else if(incomingByte == 'f'){
      Serial.println(carro.velocidad);
      carro.cambiarVelocidad(-20);
    }else {
      carro.detener();
    }
  }else{
    carro.detener();
  }
}
