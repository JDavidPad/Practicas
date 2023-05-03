/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trigger A1
#define echo A2
#define alarma 9
int dis;
int distancia;
long tIem;
LiquidCrystal_I2C LCD_Padilla(direccion_lcd, columnas, filas);
byte bloque[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
void setup()
{
Serial.begin(9600);
for(int i=2; i<=11;i++){
pinMode(i, OUTPUT);
}
pinMode(alarma ,OUTPUT);
pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  LCD_Padilla.init();
  LCD_Padilla.backlight();
  LCD_Padilla.createChar(1, bloque);
}
void loop()
{
  Serial.println(dis);
  medicion();
   distancia = dis;
  alerta();
}
int medicion(){
 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  tIem = pulseIn(echo, HIGH);
  dis = tIem/59;
  delay(50);
  return dis;
}
void alerta(){
   if( distancia == 50){  
    LCD_Padilla.setCursor(0,0);
    LCD_Padilla.print("                ");
    LCD_Padilla.setCursor(0,0);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.setCursor(7,0);
    LCD_Padilla.print("50");
    LCD_Padilla.setCursor(13,0);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("     LIBRE      ");
  }
  if( distancia == 30){
    LCD_Padilla.setCursor(0,0);
    LCD_Padilla.print("                ");
    LCD_Padilla.setCursor(0,0);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.setCursor(7,0);
    LCD_Padilla.print("30");
    LCD_Padilla.setCursor(11,0);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("     CUIDADO    ");
  }
  if( distancia == 10){
    LCD_Padilla.setCursor(0,0);
    LCD_Padilla.print("                ");
    LCD_Padilla.setCursor(0,0);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.setCursor(7,0);
    LCD_Padilla.print("10");
    LCD_Padilla.setCursor(9,0);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.write(1);
    LCD_Padilla.setCursor(0,1);
    LCD_Padilla.print("      ALTO      ");
  }
  }
