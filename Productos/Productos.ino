/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
 int a=0;
  int p = 0;
#define pin1 8
#define pin 12
#define configInput(pin)       pinMode(pin,input)
  struct deproducto{
  char nombredelproducto[30];
  char Quetzales[5];
  double preciounitario;
  int stock;
  int Reserva;
  double precioporellote;
};
deproducto Doritos = {"Doritos Nachos Atrevido","Q",1.5,85,150};
deproducto Gatorade = {"Azul","Q",7.5,25,80};
deproducto Shampoo = {"Pelo Riso","Q",70,15,20};
deproducto papelhigienico = {"Scott","Q",5,25,40};
void setup() 
{
Serial.begin(9600);
pinMode(pin,INPUT);
pinMode(pin1,INPUT);
Serial.println("Bienvenidos a la tiendita de La Bendicion");
}
void loop() 
{
if( digitalRead(pin)==HIGH){
  a=1;
p++;
delay(200);}
if( p>3){
p=0;}

if( digitalRead(pin1)==HIGH){
   a=1;
  p--;
  delay(200);}
if( p<0){
p=3;}
while(a==1){
switch(p){
case (0):
Serial.println("******************************");
Serial.println(Doritos.nombredelproducto);
Serial.print("Q.");
Serial.println(Doritos.preciounitario);
Serial.println(Doritos.stock);
Serial.println(Doritos.Reserva);
Serial.println(Doritos.preciounitario*Doritos.stock);
Serial.println("******************************");
a=2;
break;

case (1):
Serial.println("******************************");
Serial.println(Gatorade.nombredelproducto);  
Serial.print("Q.");
Serial.println(Gatorade.preciounitario);
Serial.println(Gatorade.stock);
Serial.println(Gatorade.Reserva);
Serial.println(Gatorade.preciounitario*Gatorade.stock);
Serial.println("******************************");
a=2;
break;

case (2):
Serial.println("******************************");
Serial.println(Shampoo.nombredelproducto);  
Serial.print("Q.");
Serial.println(Shampoo.preciounitario);
Serial.println(Shampoo.stock);
Serial.println(Shampoo.Reserva);
Serial.println(Shampoo.preciounitario*Shampoo.stock);
Serial.println("******************************");
a=2;
break;

case (3):
Serial.println("******************************");
Serial.println(papelhigienico.nombredelproducto);  
Serial.print("Q.");
Serial.println(papelhigienico.preciounitario);
Serial.println(papelhigienico.stock);
Serial.println(papelhigienico.Reserva);
Serial.println(papelhigienico.preciounitario*papelhigienico.stock);
Serial.println("******************************");
a=2;
break;

}
}
}
