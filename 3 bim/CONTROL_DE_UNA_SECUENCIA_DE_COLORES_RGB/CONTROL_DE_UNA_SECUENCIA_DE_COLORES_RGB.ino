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
//Librerias
#include <Ticker.h>

//definicion de pines
#define GREEN 11
#define BLUE 10
#define RED 9
#define Potenciometro A0

//variables
int vlr;
int t;

//Funcion ISR
void Secuencia(void);
void tiempo(void);

//Función Ticker
Ticker cambio(tiempo, 1);
void setup()
{
  Serial.begin(9600);//inicializar la comunicación Serial
  pinMode(10,OUTPUT);//Declarar pin 10 como salida PWM
  pinMode(A0,INPUT);//Declarar pin A0 como Entrada
  pinMode(11,OUTPUT);//Declarar pin 11 como salida PWM
  pinMode(9,OUTPUT);//Declarar pin 9 como salida PWM
}

void loop()
{
 cambio.update();
 tiempo();
 Secuencia();
}

void tiempo(){
  vlr = analogRead(Potenciometro);
  t = map(vlr, 0 ,1023 ,100 ,1000);
  Serial.println(t);
}

void Secuencia()
{
  //secuencia1
analogWrite(RED,174);
analogWrite(BLUE,230);
analogWrite(GREEN,92);
delay(t);

//Secuencia 2
analogWrite(RED,255);
analogWrite(BLUE,255);
analogWrite(GREEN,255);
delay(t);

//Secuencia 3
analogWrite(RED,0);
analogWrite(BLUE,255);
analogWrite(GREEN,255);
delay(t);

//Secuencia 4
analogWrite(RED,189);
analogWrite(BLUE,20);
analogWrite(GREEN,174);
delay(t);

//Secuencia 5
analogWrite(RED,255);
analogWrite(BLUE,87);
analogWrite(GREEN,35);
delay(t);
}
