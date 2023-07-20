/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Josué David Padilla Morataya
 * CARNE: 2022074
 * Proyecto: Nivelador
*/
#include <Wire.h>
#include <SPI.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>

//Directivas
#define ancho_matriz 8 
#define alto_matriz 8
#define DATO_PIN 12
#define CLK_PIN 11
#define CS_PIN 10

//Variables
float xg,yg,zg;
float soh;
float tilt;
float angle;

const byte desnivelIzquierda5[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00000010,
  B00000010,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelIzquierda4[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00000110,
  B00000110,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelIzquierda3[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00000100,
  B00000100,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelIzquierda2[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00001100,
  B00001100,
  B11111111,
  B00000000,
  B00000000
  };

const byte desnivelIzquierda1[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00001000,
  B00001000,
  B11111111,
  B00000000,
  B00000000
  };

const byte centrado[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00011000,
  B00011000,
  B11111111,
  B00000000,
  B00000000};

const byte desnivelDerecha1[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00010000,
  B00010000,
  B11111111,
  B00000000,
  B00000000};

const byte desnivelDerecha2[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00110000,
  B00110000,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelDerecha3[8] = {
  B00000000,
  B00000000,
  B11111111,
  B00100000,
  B00100000,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelDerecha4[8] = {
  B00000000,
  B00000000,
  B11111111,
  B01100000,
  B01100000,
  B11111111,
  B00000000,
  B00000000
};

const byte desnivelDerecha5[8] = {
  B00000000,
  B00000000,
  B11111111,
  B01000000,
  B01000000,
  B11111111,
  B00000000,
  B00000000
};

//Constructores
LedControl ledMatrix = LedControl(DATO_PIN,CLK_PIN,CS_PIN,1);
ADXL345 NIVEL = ADXL345();
void setup() {
   Serial.begin(9600);    
   ledMatrix.shutdown(0,false);    
   ledMatrix.setIntensity(0,15);  
   ledMatrix.clearDisplay(0);    
   NIVEL.powerOn();           
   NIVEL.setRangeSetting(8);

}

void loop() {
   nivelacion();
   animacion();
   
}

void nivelacion(){
  int sumax = 0;
  int x, y, z;
  NIVEL.readAccel(&x, &y, &z);
     xg = x*0.0039;
     yg = y*0.0039;
     zg = z*0.0039;
     soh = xg/zg;

     tilt = atan(soh)*57.296;
}

void animacion(){
  Serial.println(tilt);
  if((abs(tilt) > 90)){  
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelDerecha5[i]);
      }
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelIzquierda5[i]);
      }
  }
  
  if((tilt < -60) && ( tilt >= -90) ){  
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelIzquierda5[i]);
      }
  }
  
  if((tilt < -45) && (tilt >= -60 )){  
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelIzquierda4[i]);
      }
  }
  if((tilt < -30) && (tilt >= -45 )){ 
    for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelIzquierda3[i]);
      }
  }

  if((tilt < -15) && (tilt >= -30 )){ 
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelIzquierda2[i]);
      }
  }
  
  if((tilt < -5) && (tilt >= -15 )){ 
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelIzquierda1[i]);
      }
  }
  
  if(tilt >= -5 && tilt <= 5){ 
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, centrado[i]);
      }
  }

  if((tilt > 5) && (tilt <= 15 )){  
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelDerecha1[i]);
      }
  }
  
  if((tilt > 15) && (tilt <= 30 )){  
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelDerecha2[i]);
      }
  }

  if((tilt > 30) && (tilt <= 45 )){  
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelDerecha3[i]);
      }
  }
  
  if((tilt > 45) && (tilt <= 60 )){  
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelDerecha4[i]);
      }
  }
  if((tilt > 60) && (tilt <= 90 )){
   for (int i = alto_matriz; i > 0; i--) {
    ledMatrix.setColumn(0, i, desnivelDerecha5[i]);
      }
  }
  }
