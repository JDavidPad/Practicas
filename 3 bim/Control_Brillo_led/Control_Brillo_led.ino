/*
Fundacion Kinal
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
Proyecto: Control Brillo led
*/

//definicion de pines
#define ld 10
#define Potenciometro A0

//variables
int Luz;
int Vlr;
//Funcion ISR
void led(void);

//
void setup()
{
  Serial.begin(9600);//inicializar la comunicación Serial
  pinMode(10,OUTPUT);//Declarar pin 10 como salida PWM
  pinMode(A0,INPUT);//Declarar pin A0 como Entrada
}

void loop()
{
 led();
}
void led()
{
  Vlr=analogRead(Potenciometro);
  Serial.println(Vlr);
  Luz = map(Vlr, 0 , 1023 , 0 , 255);
  analogWrite(10,Luz);
  delay(100);
  
}
