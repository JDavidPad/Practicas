/*
   Centro Educativo Tecnico Laboral Kinal
   Quinto perito en electronica
   EB5AM
   Taller de electronica digital y reparacion de computadoras
   Nombres: Edgar Leonel Ramirez Estrada 2019410(coordinador)
            Álvaro Anzueto Rodas 2019733
            Joué David Padilla Morataya 2022074
            Juan Manuel Sebastián Ixen Coy 2019519
            
   Fecha: 25/05/2023
   Proyecto Final del Segundo Bimestre
   Proyecto: casa domotizada    Grupo No.7
*/

//Se incluyen las librerias utilizar//
#include <DallasTemperature.h>
#include <OneWire.h>

//Se cambia de nombre a las entradas, salidas,alto y bajo//
#define entrada(pin) pinMode(pin,INPUT)
#define salida(pin) pinMode(pin,OUTPUT)
#define pin_high(pin) digitalWrite(pin,HIGH)
#define pin_low(pin) digitalWrite(pin,LOW)

//Se definen los pines a utilizar//
#define envio_temp 16
#define envio_parqueo 17
#define trig 5
#define echo 6
#define rele_6 10
int distance;
int duration;

//TEMPERATURA//
OneWire ourWire(8);
DallasTemperature ventilador_casa(&ourWire);
float cel;

//Se nombran las entradas y salidas de los pines a utilizar//
void setup() {
  Serial.begin(9600);
  entrada(echo);
  salida(trig);
  salida (envio_parqueo);
  salida (envio_temp);
  salida (rele_6);

}

//Se llaman a las funciones hechas para realizar el comportamiento del ultrasonico y el sensor de temperatura//
void loop() {
  ultrasonico();
  comportamiento_ultrasonico();
  cel = temperaturaC();
  calefaccion();
  Serial.println(cel);
}

void ultrasonico() {
  pin_high(trig); //Se programo el comportamiento que tendra el trig y el echo para que nos de valores en cm//
  delay(1);
  pin_low(trig);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58;
  delay(500);
  Serial.print(distance);
  Serial.println(" cm");
}

void comportamiento_ultrasonico() {//Se le disponen los rangos que tendran en lectura//
  if (distance >= 0 && distance <= 10) {
    Serial.println("Hay carro");
    pin_high(envio_parqueo);//de 0 a 5 cm detectara un carro o presencia//
  }
  else if (distance > 10) {
    Serial.println("No hay carro"); //si es mayor a 5 nos dira que no hay carro//
    pin_low(envio_parqueo);
  }
}

void calefaccion() { //Se realiza las medidas con las cuales se encendera y apagara nuestro rele//
  if (cel > 27 ) {
    pin_high(rele_6);//Si es mayor o igual a 25 se encendera el rele//
    pin_low(envio_temp);
  }
  if (cel >= 0 && cel <= 27) {
    pin_low(rele_6);//Si es menor a 25 se apagara el rele//
    pin_high(envio_temp);
  }
}
int temperaturaC() { //Se programa la temperatura para que los valores expuestos sean en °C//
  ventilador_casa.requestTemperatures();
  int temp = ventilador_casa.getTempCByIndex(0);
  return temp;
}
