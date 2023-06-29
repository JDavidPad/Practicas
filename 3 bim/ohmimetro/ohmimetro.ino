/*
Fundacion Kinal
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
Proyecto:CONTROL DE UNA SECUENCIA DE COLORES RGB 
*/
//librerias
#include <LiquidCrystal_I2C.h> 

//Directivas de procesador
#define Enter A0

//Variables
float vlr_entrada;
float Parte_1;
int Vcc=5;
float Parte_2;
int Res;
int res2 = 10000;
int res1;
//
void formula(void);
//Constructor
LiquidCrystal_I2C LCD_Padilla(0x27, 16, 2);

void setup(){
  Serial.begin(9600);
LCD_Padilla.init(); 
LCD_Padilla.backlight(); 
LCD_Padilla.setCursor(3,0);
LCD_Padilla.print ("Ohmimetro");
  pinMode(A0, INPUT);
  }
  
void loop(){
  formula();
}
void formula(){
  vlr_entrada = analogRead(Enter);
  vlr_entrada =(Vcc * vlr_entrada) / 1023;
  if (vlr_entrada){
  Parte_1= Vcc - vlr_entrada; 
  Parte_2 = vlr_entrada;
  res1 = (Parte_1/Parte_2) * res2;
  LCD_Padilla.setCursor(4,1); 
  LCD_Padilla.print(res1);
   LCD_Padilla.print("            ");
   Serial.println(res1);
  }
  }
