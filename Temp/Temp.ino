/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#include <OneWire.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define direccion_lcd 0x27
#define columnas 15 
#define filas 2   
#include <DallasTemperature.h>
#define led_R 5
#define led_B 6
#define led_Y 7
OneWire ourWire(4);
DallasTemperature sensors(&ourWire);
LiquidCrystal_I2C LCD_Padilla(direccion_lcd, columnas, filas);
byte normal[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B10101,
  B00100,
  B01010  
};
byte Caliente[] = {
  B00100,
  B00110,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110
};
byte Frio[] = {
  B00100,
  B10101,
  B01110,
  B11110,
  B11111,
  B01110,
  B10101,
  B00100
};
byte grados[] = {
  B00000,
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000
};
void setup() {
Serial.begin(9600);
pinMode(led_R,OUTPUT);
pinMode(led_B,OUTPUT);
pinMode(led_Y,OUTPUT);
delay(1000);
sensors.begin();
LCD_Padilla.init();
LCD_Padilla.backlight();
LCD_Padilla.createChar(1,normal);
LCD_Padilla.createChar(2,Caliente);
LCD_Padilla.createChar(3,Frio);
LCD_Padilla.createChar(4,grados);
}
void loop() {
  sensor();
}
void sensor(){
sensors.requestTemperatures();
int temp= sensors.getTempCByIndex(0);
int temp1 = sensors.getTempFByIndex(0);
if(temp >= 30){
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("                ");
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("Temp= ");
LCD_Padilla.print(temp);
LCD_Padilla.setCursor(14,0);
LCD_Padilla.write(4);
LCD_Padilla.setCursor(15,0);
LCD_Padilla.println("C");
delay(100);  
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("Temp=");
LCD_Padilla.print(temp1);
LCD_Padilla.setCursor(14,0);
LCD_Padilla.write(4);
LCD_Padilla.setCursor(15,1);
LCD_Padilla.println("F");
delay(100);
LCD_Padilla.setCursor(15,1);
LCD_Padilla.write(2);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
}
if((temp >= 15)&&(temp <= 29)){
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("                ");
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("Temp= ");
LCD_Padilla.print(temp);
LCD_Padilla.setCursor(14,0);
LCD_Padilla.write(4);
LCD_Padilla.setCursor(15,0);
LCD_Padilla.println("C");
delay(100);  
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("Temp=");
LCD_Padilla.print(temp1);
LCD_Padilla.setCursor(14,0);
LCD_Padilla.write(4);
LCD_Padilla.setCursor(15,1);
LCD_Padilla.println("F");
delay(100);
LCD_Padilla.setCursor(15,1);
LCD_Padilla.write(1);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,HIGH);
}
if(temp <= 14){
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("                ");
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("Temp= ");
LCD_Padilla.print(temp);
LCD_Padilla.setCursor(14,0);
LCD_Padilla.write(4);
LCD_Padilla.setCursor(15,0);
LCD_Padilla.println("C");
delay(100);  
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("Temp=");
LCD_Padilla.print(temp1);
LCD_Padilla.setCursor(14,0);
LCD_Padilla.write(4);
LCD_Padilla.setCursor(15,1);
LCD_Padilla.println("F");
delay(100);
LCD_Padilla.setCursor(15,1);
LCD_Padilla.write(3);
digitalWrite(5,LOW);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
}
}
