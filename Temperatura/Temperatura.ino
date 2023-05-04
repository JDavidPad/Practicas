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
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
LiquidCrystal_I2C LCD_PadillaJosue(direccion_lcd, columnas, filas); 
byte customChar1[] = {
 B00100,
  B01110,
  B11111,
  B01110,
  B01110,
  B11111,
  B01110,
  B11011
};
byte customChar2[] = {
  B01000,
  B10100,
  B01000,
  B00111,
  B00100,
  B00110,
  B00100,
  B00100
};
void setup()
{
  Serial.begin(9600);
  LCD_PadillaJosue.init();
  LCD_PadillaJosue.backlight();
  LCD_PadillaJosue.createChar(1, customChar1);
  LCD_PadillaJosue.createChar(2, customChar2);
}
void loop()
{
  LCD_PadillaJosue.setCursor(0,0);
  LCD_PadillaJosue.print("   Temperatura   ");
  delay(2000);
  LCD_PadillaJosue.setCursor(0,1);
  LCD_PadillaJosue.print("      Tienes      ");
  delay(2000);
  LCD_PadillaJosue.setCursor(0,0);
  LCD_PadillaJosue.setCursor(0,1);
  LCD_PadillaJosue.print("                ");
  LCD_PadillaJosue.setCursor(3,0);
  LCD_PadillaJosue.write(1);
  LCD_PadillaJosue.write(1);
  LCD_PadillaJosue.write(1);
  LCD_PadillaJosue.write(1);
  LCD_PadillaJosue.write(1);
  LCD_PadillaJosue.write(1);
  LCD_PadillaJosue.write(1);
  LCD_PadillaJosue.write(1);
  LCD_PadillaJosue.write(1);
  delay(2000);
}
