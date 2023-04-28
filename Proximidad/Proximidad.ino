/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#include <Wire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trigger A2
#define echo A1
#define alarm A0
int dis;
int i;
long tim; 
LiquidCrystal_I2C LCD_Padilla(direccion_lcd, columnas, filas);
void setup()
{
Serial.begin(9600);
for(i=2; i<=11;i++){
pinMode(i, OUTPUT);
}
pinMode(alarm ,OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
LCD_Padilla.init();
LCD_Padilla.backlight();
}
void loop()
{
Serial.println(dis);
medicion();
alerta();
}
int medicion(){
digitalWrite(trigger, HIGH);
delayMicroseconds(10); 
digitalWrite(trigger, LOW);
tim = pulseIn(echo, HIGH);
dis = tim/59;
delay(50);
return dis;
}
void alerta(){
if( dis > 45){
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("FUERA DE ALCANCE");
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("");
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(alarm, LOW);
}
if( dis < 45 && dis > 30){
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print(" Persona/objeto ");
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("   Acercandose  ");
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(alarm, LOW);
}
if( dis < 30 && dis > 15){
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("   Cuidado,  ");
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("Espacio Privado");
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(alarm, HIGH);
delay(5000);
digitalWrite(alarm, LOW);
}   
if( dis < 15 && dis > 0){
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print(" Invadiendo  ");
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("Espacio Privado");
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(alarm, HIGH);
delay(10000);
digitalWrite(alarm, LOW);
}
else {
digitalWrite(alarm, LOW);
}
}
