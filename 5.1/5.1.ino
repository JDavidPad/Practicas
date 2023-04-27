/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#include <LiquidCrystal.h>
#define RS  6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5
LiquidCrystal LCD_Padilla(RS,Enable,D4,D5,D6,D7);
void setup(){
LCD_Padilla.begin(16,2);
LCD_Padilla.setCursor(0,0);
LCD_Padilla.print("Josue");
LCD_Padilla.setCursor(0,1);
LCD_Padilla.print("2022074");
}
void loop()
{
}
