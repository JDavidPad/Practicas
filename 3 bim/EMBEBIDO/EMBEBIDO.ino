/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#include <LedControl.h>
#include <Ticker.h>

#define DATO_PIN 12
#define CS_PIN 11
#define CLK_PIN 10
void Lectura_Alcohol(void);
LedControl ledMatrix = LedControl(DATO_PIN,CLK_PIN,CS_PIN,1);
Ticker ISR_Alcohol(Lectura_Alcohol, 5000);
#define AlcoholSensorPin  A0

//Confuguración matriz led
const int ancho_matriz = 8; 
const int alto_matriz = 8; 
int Alcoholes;
int prom;

byte Gas[8] = {
B00000010,
B00000100,
B00001100,
B00011100,
B00111110,
B01111111,
B00111110,
B00011100
};
byte Humo[8] = {
B00000000,
B00000100,
B00001100,
B01001100,
B01111000,
B00111101,
B01111110,
B00111110
};
byte Alcohol [8] = {
B10100101,
B01000010,
B10100101,
B00011000,
B00011000,
B10100101,
B01000010,
B10100101
};

void setup() {
  ledMatrix.shutdown(0, false); 
  ledMatrix.setIntensity(0, 15); 
  ledMatrix.clearDisplay(0); 
  pinMode(AlcoholSensorPin, INPUT); 
  ISR_Alcohol.start();
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del sensor de Alcohol
 ISR_Alcohol.update();
  if (prom > 60) {
    alerta_Gas();
  } else {
    for (int i = 0; i < alto_matriz; i++) {
    ledMatrix.setColumn(0, i, Alcohol[i]);
  }
  }
  delay(1000);
}
void Lectura_Alcohol(){
  int suma =0;
  for(int i = 0; i < 5; i++){
  Alcoholes = map(analogRead(AlcoholSensorPin),0,1023,0,100);
  suma = suma + Alcoholes;
  delay(100);
  }
  prom = suma/5;
  Serial.println(Alcoholes);
}
void alerta_Gas() {
  ledMatrix.clearDisplay(0);
  for(int t = 0; t<5;t++){
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, Gas[i]);
    }
    delay(500);
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, Humo[i]);
    }
    delay(500);
    }
} 
