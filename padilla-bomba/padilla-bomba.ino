/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Blumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#define sensor 6
#define bomba 5 
#define vacio 4//azul
#define lleno 3//verde
void setup() {
 pinMode(sensor, INPUT);
 pinMode(bomba, OUTPUT);
 pinMode(vacio, OUTPUT);
 pinMode(lleno, OUTPUT);
}
void loop() {
int estado;
estado = digitalRead(sensor);
if (estado == HIGH){
digitalWrite(vacio, HIGH);
digitalWrite(lleno, LOW);
digitalWrite(bomba, HIGH);
}
estado = digitalRead(sensor);
if (estado == LOW){
digitalWrite(vacio, LOW);
digitalWrite(lleno, HIGH);
digitalWrite(bomba, LOW);
delay(1000);
} 
}
