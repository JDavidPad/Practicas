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
#include <DallasTemperature.h>
#include <Wire.h>
#include <OneWire.h>
#include <Ticker.h>

//Directivas
#define pinTXD_BT 10
#define pinRXD_BT 11
#define pinLed 5
#define pinTemp 6

//Variables
int Estado;
String request;

//Funciones
void Temperature_medition(void);

//Constructores
SoftwareSerial BT_PAD(pinTXD_BT,pinRXD_BT);  //Define los pines del modulo HC-06
OneWire ourWire(pinTemp);  //Pin 6 para el sensor de temperatura
DallasTemperature sensor(&ourWire);
Ticker ISR_GET_TEMP(Temperature_medition, 10000);

void setup() {
  BT_PAD.begin(9600);
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT),
  sensor.begin(); 
    ISR_GET_TEMP.start();
}
void loop() {
  if(BT_PAD.available()>0){
    Estado = BT_PAD.parseInt(); 
    if(Estado == 1){
      digitalWrite(pinLed, HIGH);
      }
    if(Estado == 2){
      digitalWrite(pinLed, LOW);
      }
    }    
     ISR_GET_TEMP.update();
}
void Temperature_medition(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  int temp = sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  BT_PAD.println(temp);
  Serial.println(temp);
  }
