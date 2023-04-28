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
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define echo 8
#define trigger 9
#define alarma 11
int Personas = 0;
int dis;
int i;
LiquidCrystal LCD_Padilla (RS,E,D4,D5,D6,D7);

byte Nio1[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010
};
byte Nio2[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B00100,
  B01010
};
void setup() {
  LCD_Padilla.begin(16,2);
  LCD_Padilla.clear();
  LCD_Padilla.createChar(1, Nio1);
  LCD_Padilla.createChar(2, Nio2);
  Serial.begin(9600);
  pinMode(alarma, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  LCD_Padilla.setCursor(0,0);
  LCD_Padilla.print("PERSONAS DENTRO:");
  digitalWrite(alarma, LOW);
}
void loop(){
  Serial.println(dis);
  medicion();
  personas();
  
}
int medicion(){
  long tim; 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  tim = pulseIn(echo, HIGH);
  dis = tim/59;
  delay(500);
  return dis;
}
 void personas(){
    if((dis >= 6) && (dis <= 10)){
      if(Personas <= 15){
    Personas++;
    int avance = Personas -1;
    LCD_Padilla.setCursor(avance, 1);
    LCD_Padilla.write(1);
    delay(10);
    LCD_Padilla.write(2);
    Serial.print("Cantidad de personas: ");
    Serial.println(Personas);
    delay(500);}
    if( Personas >= 16){
    exceso();
      }
    }
    }
void exceso(){
      digitalWrite(alarma, HIGH);
      LCD_Padilla.setCursor(0,0);
      LCD_Padilla.print("CAPACIDAD MAXIMA"); 
      LCD_Padilla.setCursor(0,1);
      LCD_Padilla.print("   ALCANZADA     ");
      delay(2000);
      digitalWrite(alarma, LOW);
      delay(100);
      }
