/*
Fundacion Kinal
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
Proyecto: Uso de interrupciones de termorizador
*/
#include <Ticker.h> //Esta libreria permite hacer uso del timer
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

//Directivas de preprocesador
#define btn 8

//Variables
volatile static bool EST_sensor;
float temperatura;

//Funciones de ISR
void ISR_temp(void);
void ISR_deteccion_btn(void);

//Constructor
Ticker ISR_obtener_temp(ISR_temp, 3000); //Cada 3 segundos obtiene la temperatura
Ticker ISR_obtener_btn(ISR_deteccion_btn, 6000); //Cada 3 segundos obtiene la temperatura
OneWire ourWire(5);  //Pin 5 para el sensor de temperatura
DallasTemperature sensor(&ourWire);

void setup() {
Serial.begin(19200);
ISR_obtener_temp.start(); //Iniciciando la interrupcion que se repetira cada N segundos
ISR_obtener_btn.start(); //Iniciciando la interrupcion que se repetira cada N segundos
sensor.begin(); 
}
void loop() {
  ISR_obtener_temp.update();
  ISR_obtener_btn.update();
}
void medicion(){
  sensor.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp = sensor.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.print("Temperatura= ");
  Serial.print(temp);
  Serial.println(" C ");
  }
void ISR_temp(){
   medicion(); 
}
void ISR_deteccion_btn(){
  bool estado_btn = digitalRead(btn);
  if(estado_btn == 1){
  Serial.println("boton activo");
}
if(estado_btn == 0){
  Serial.println("boton inactivo");
}
}
