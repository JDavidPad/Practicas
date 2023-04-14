/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Blumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
int estado=2;
#define led
void setup() {
for(estado;estado<=12;estado++){
  pinMode(estado,OUTPUT);
}
}
void loop(){
estado=2;
for(led;estado<=11;estado++){
  digitalWrite(estado, HIGH);
  delay(100);
  digitalWrite(estado, LOW);
}
estado=11;
for(led;estado>=2;estado--){
    digitalWrite(estado, HIGH);
  delay(100);
  digitalWrite(estado, LOW);
}
}
