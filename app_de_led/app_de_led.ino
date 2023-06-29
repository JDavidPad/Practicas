/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#include <SoftwareSerial.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <Wire.h>

//variables 
OneWire ourWire(4);
SoftwareSerial Bluetooth(10,11);

char Recibe;
void setup(){
  Serial.begin(9600);
  Serial.println("Listo");
  Bluetooth.begin(38400);
  pinMode(12,OUTPUT);
  pinMode(7,INPUT);
}
void loop(){
  if(Bluetooth.available()){
    //Serial.write(Bluetooth.read());
    Recibe=Bluetooth.read();
    Serial.println(Recibe);
    if(Recibe==1){
      Serial.println("Encendido");
      digitalWrite(12,HIGH);
    }
        if(Recibe==2){
          Serial.println("Apagado");
      digitalWrite(12,LOW);
    }
  }
  if(Serial.available()){
    Bluetooth.write(Serial.read());
  }
  sensors.requestTemperatures();
  int temp= sensors.getTempCByIndex(0);
  Serial.Print(temp);  
}
