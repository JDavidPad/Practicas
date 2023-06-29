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
#include <DallasTemperature.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h> 
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
//Directivas
#define btn1 11
#define btn2 12
#define btn3 10
#define led1 14
#define led2 15
#define Cantidad_Leds 7
#define pin_Led 6
#define RadarPin A2
#define pin_Servo 3
#define buzzer 13
#define R 8
#define G 9
#define B 7
int personacerca =0;
int esta;
int estado1 = 0;
int estado2 = 0;
Adafruit_NeoPixel ruedaP(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);
byte puerta_cerrada[] = {
  B11111,
  B11111,
  B11111,
  B11101,
  B11111,
  B11111,
  B11111,
  B11111
};
byte puerta_mediocerrada[] = {
  B11000,
  B11100,
  B11110,
  B11010,
  B11110,
  B11110,
  B11100,
  B11000
};
byte puerta_media_abierta[] = {
  B11000,
  B11100,
  B11110,
  B11010,
  B11110,
  B11110,
  B11100,
  B11000
};
byte puerta_abierta[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
byte luz_off[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B01010,
  B01110,
  B01110
};
byte luz_on[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B01110,
  B01110
};
byte Grados_centigrados[] = {
  B01000,
  B10100,
  B01000,
  B00011,
  B00100,
  B00100,
  B00100,
  B00011
};
byte persona_detectada[] = {
  B01000,
  B11100,
  B00000,
  B01110,
  B01110,
  B01110,
  B00100,
  B11111
};
byte persona_nodetectada[] = {
  B10100,
  B01000,
  B10100,
  B01110,
  B01110,
  B01110,
  B00100,
  B11111
};
int medicion();
void puerta();
OneWire ourWire(2);
DallasTemperature sensor(&ourWire);
LiquidCrystal_I2C LCD_Padilla(0x27, 16, 2);
Servo Servomotor_Padilla; 
int temperatura;
void setup(){
  Servomotor_Padilla.attach(pin_Servo);
  pinMode(RadarPin, INPUT);
  ruedaP.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
sensor.begin(); 
LCD_Padilla.init(); 
LCD_Padilla.backlight(); 
LCD_Padilla.createChar(1, puerta_abierta);
LCD_Padilla.createChar(2, puerta_media_abierta);
LCD_Padilla.createChar(3, puerta_cerrada);
LCD_Padilla.createChar(4, luz_off);
LCD_Padilla.createChar(5, luz_on);
LCD_Padilla.createChar(6, Grados_centigrados);
LCD_Padilla.createChar(7, persona_detectada);
LCD_Padilla.createChar(8, persona_nodetectada);
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("Puerta:");
LCD_Padilla.setCursor(9,1);
LCD_Padilla.print("Luz 2");
LCD_Padilla.write(5);
LCD_Padilla.setCursor(9,0);
LCD_Padilla.print("Luz 1");
LCD_Padilla.write(4);
Servomotor_Padilla.write(0);
 }
void loop() {
esta = digitalRead(RadarPin);
luminarias();
puerta();
temperatura = medicion();
luminarias();
puerta();
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print(temperatura);
LCD_Padilla.write(6);
luminarias();
puerta();
proximidad();
luminarias();
puerta();
condicion_temp();
luminarias();
puerta();
}
int medicion(){
sensor.requestTemperatures();
int temp = sensor.getTempCByIndex(0);
Serial.print("Temperatura= ");
Serial.print(temp);
Serial.println(" C");
delay(100);  
return temp;
}
void proximidad(){  
if( esta == LOW){
LCD_Padilla.setCursor(7,0);
LCD_Padilla.write(8);
for(int i = 0; i < 7; i++){
ruedaP.setPixelColor(i,ruedaP.Color(0,255,0));
ruedaP.show();
delay(50);
ruedaP.setPixelColor(i,ruedaP.Color(0,40,10));
ruedaP.show();
delay(50);
}
}   
if(esta == HIGH){
LCD_Padilla.setCursor(7,0);
LCD_Padilla.write(7);
digitalWrite(buzzer, HIGH);
for(int i = 0; i < 7; i++){
ruedaP.setPixelColor(i,ruedaP.Color(189,255,0));
ruedaP.show();
delay(50);
ruedaP.setPixelColor(i,ruedaP.Color(0,201,255));
ruedaP.show();
delay(50); 
}
digitalWrite(buzzer, LOW);
}if(personacerca == 0){    
}
}
void luminarias(){
if(digitalRead(btn1) && estado1==0){
    digitalWrite(led1, LOW);
    LCD_Padilla.setCursor(9,0);
    LCD_Padilla.print("Luz 1");
    LCD_Padilla.write(5);
    delay(300);
    estado1=1;
    }
  if(digitalRead(btn1) && estado1==1){
    digitalWrite(led1, HIGH); 
    LCD_Padilla.setCursor(9,0);
    LCD_Padilla.print("Luz 1");
    LCD_Padilla.write(4);
    delay(300); 
    estado1=0;
    }
  if(digitalRead(btn2) && estado2==0){
    digitalWrite(led2, LOW);    
    LCD_Padilla.setCursor(9,1);
    LCD_Padilla.print("Luz 2");
    LCD_Padilla.write(5); 
    delay(300);
    estado2=1;   
  } 
  if(digitalRead(btn2) && estado2==1){
    digitalWrite(led2, HIGH);
    LCD_Padilla.setCursor(9,1);
    LCD_Padilla.print("Luz 2");
    LCD_Padilla.write(4); 
    delay(300);
    estado2=0;
  }
}
void puerta(){
  if(digitalRead(btn3)==HIGH){
  Servomotor_Padilla.write(90);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("Puerta:");
    LCD_Padilla.write(3);
    delay(100);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("Puerta:");
    LCD_Padilla.write(2);
    delay(100);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("Puerta:");
    LCD_Padilla.write(1); 
    delay(2000);
    Servomotor_Padilla.write(0);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("Puerta:");
    LCD_Padilla.write(1);
    delay(100);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("Puerta:");
    LCD_Padilla.write(2);
    delay(100);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("Puerta:");
    LCD_Padilla.write(3);
    delay(1000); 
    Servomotor_Padilla.write(90);
  } else{
    Servomotor_Padilla.write(0);
    }
}
void condicion_temp(){
if(temperatura > 15 && temperatura <= 21){
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}
if(temperatura > 21 && temperatura <= 25){
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(B, LOW);
}
if(temperatura > 25 && temperatura < 45){
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}
}
