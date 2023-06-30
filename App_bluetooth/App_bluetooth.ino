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
DallasTemperature sensors(&ourWire);
SoftwareSerial Bluetooth(8,10);
//Variable
char Recibe;
void setup(){
  Serial.begin(9600);
  Serial.println("Listo");
  Bluetooth.begin(38400);
  pinMode(12,OUTPUT);
  pinMode(4,INPUT);
}
void loop(){
  if(Bluetooth.available()){
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
  Serial.print(temp);  
}
