/*
Fundacion Kinal
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
Proyecto: Uso de interrupciones de termorizador
*/

//definir variables a usar
  #define Boton_Descendente 2
  #define Boton_ascendente 3
  //display 1
  #define a1 4
  #define b1 5
  #define c1 6
  #define d1 7
  #define e1 8
  #define f1 9
  #define g1 10
//display 2
  #define a2 11
  #define b2 12 
  #define c2 13
  #define d2 14
  #define e2 15
  #define f2 16
  #define g2 17
  #define bled 13

//funciones ISR
  void funcion_ISR_DES(void);
  void funcion_ISR_ASC(void);
  void integrar_num(void);
  void desintegrar_num(void);

//Funciones
int Conteo();
void display_U(void);
void display_D(void);
 
//Variables para Volatile Static
  volatile static bool fin_con1 = false;
  volatile static bool fin_con2 = false;
   
// Variables
int AGG_U = 0;
void setup() 
  {
  Serial.begin(19200);
  pinMode(Boton_Descendente,INPUT);
  pinMode(Boton_ascendente,INPUT);
  attachInterrupt(digitalPinToInterrupt(Boton_Descendente),funcion_ISR_DES,RISING);
  attachInterrupt(digitalPinToInterrupt(Boton_ascendente),funcion_ISR_ASC,FALLING);
  pinMode(a1,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(c1,OUTPUT);
  pinMode(d1,OUTPUT);
  pinMode(e1,OUTPUT);
  pinMode(f1,OUTPUT);
  pinMode(g1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(c2,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(e2,OUTPUT);
  pinMode(f2,OUTPUT);
  pinMode(g2,OUTPUT);
  pinMode(bled ,OUTPUT);

  }

void loop() 
  {
 if(AGG_U >50){
  AGG_U = 0;
 }
  if(AGG_U < 0){
  AGG_U = 50;
 }
 display_U();
 display_D();
 fin_con1 = false;
 fin_con2 = false;
  }
 void funcion_ISR_DES(void)
  {
    
  desintegrar_num();
  
  }
 void funcion_ISR_ASC(void)
  {

  integrar_num();

  }
void integrar_num(void)
{
  AGG_U ++;
  Serial.println(AGG_U);
}
void desintegrar_num(void)
{
  AGG_U --;
  Serial.println(AGG_U);
}
//display Unidades
void display_U(void){
if (AGG_U == 0 || AGG_U == 10 || AGG_U ==20 || AGG_U == 30 ||AGG_U == 40 || AGG_U ==50){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,HIGH);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,LOW);
}
if (AGG_U == 1 || AGG_U == 11 || AGG_U ==21 || AGG_U == 31 ||AGG_U == 41){
  digitalWrite(a1,LOW);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,LOW);
  digitalWrite(e1,LOW);
  digitalWrite(f1,LOW);
  digitalWrite(g1,LOW);
}
if (AGG_U == 2 || AGG_U == 12 || AGG_U ==22 || AGG_U == 32 ||AGG_U == 42){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,LOW);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,HIGH);
  digitalWrite(f1,LOW);
  digitalWrite(g1,HIGH);
}
if (AGG_U == 3 || AGG_U == 13 || AGG_U ==23 || AGG_U == 33 ||AGG_U == 43){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,LOW);
  digitalWrite(f1,LOW);
  digitalWrite(g1,HIGH);
}
if (AGG_U == 4 || AGG_U == 14 || AGG_U ==24 || AGG_U == 34 ||AGG_U == 44){
  digitalWrite(a1,LOW);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,LOW);
  digitalWrite(e1,LOW);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
if (AGG_U == 5 || AGG_U == 15 || AGG_U ==25 || AGG_U == 35 ||AGG_U == 45){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,LOW);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,LOW);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
if (AGG_U == 6 || AGG_U == 16 || AGG_U ==26 || AGG_U == 36 ||AGG_U == 46){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,LOW);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,HIGH);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
if (AGG_U == 7 || AGG_U == 17 || AGG_U ==27 || AGG_U == 37 ||AGG_U == 47){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,LOW);
  digitalWrite(e1,LOW);
  digitalWrite(f1,LOW);
  digitalWrite(g1,LOW);
}
if (AGG_U == 8 || AGG_U == 18 || AGG_U ==28 || AGG_U == 38 ||AGG_U == 48 ){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,HIGH);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
if (AGG_U == 9 || AGG_U == 19 || AGG_U == 29 || AGG_U == 39 ||AGG_U == 49){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,LOW);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
}
//display decenas
void display_D(void){
if (AGG_U == 0 || AGG_U == 9){
  digitalWrite(a2,HIGH);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(e2,HIGH);
  digitalWrite(f2,HIGH);
  digitalWrite(g2,LOW);
}
if ( AGG_U == 10 || AGG_U ==19){
  digitalWrite(a2,LOW);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,LOW);
  digitalWrite(e2,LOW);
  digitalWrite(f2,LOW);
  digitalWrite(g2,LOW);
}
if ( AGG_U ==20 || AGG_U == 29){
  digitalWrite(a2,HIGH);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,LOW);
  digitalWrite(d2,HIGH);
  digitalWrite(e2,HIGH);
  digitalWrite(f2,LOW);
  digitalWrite(g2,HIGH);
}
if (AGG_U == 30 ||AGG_U == 39){
  digitalWrite(a2,HIGH);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(e2,LOW);
  digitalWrite(f2,LOW);
  digitalWrite(g2,HIGH);
}
if (AGG_U == 40 || AGG_U == 49){
  digitalWrite(a2,LOW);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,LOW);
  digitalWrite(e2,LOW);
  digitalWrite(f2,HIGH);
  digitalWrite(g2,HIGH);
}
if (AGG_U == 50){
  digitalWrite(a2,HIGH);
  digitalWrite(b2,LOW);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(e2,LOW);
  digitalWrite(f2,HIGH);
  digitalWrite(g2,HIGH);
}
}
