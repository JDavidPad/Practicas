/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Blumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#define Bot1 12
#define Bot2 11
#define Entrada(pin) pinMode (pin, INPUT)
#define Salida(pin) pinMode (pin, OUTPUT)
#define Encender(pin) digitalWrite (pin, HIGH)
#define Apagar(pin) digitalWrite (pin, LOW)
#define LR 5 
#define LG 4
#define LB 6
int SHITCH2; 
int SHITCH1;
void setup() {
Entrada (Bot1);
Entrada (Bot2);
Salida (LR);
Salida (LG);
Salida (LB);
}
void loop() {
SHITCH1 = digitalRead (Bot1);
SHITCH2 = digitalRead (Bot2);
if (SHITCH1 == HIGH) {
Apagar(LB);
Encender(LR);
Encender (LG);
}
if (SHITCH2 == HIGH) {
Encender(LB);
Encender (LG);
Apagar(LR);
}
if (SHITCH1 == HIGH && SHITCH2 == HIGH){
Apagar(LG);
Encender(LB);
Encender (LR);
}
if (SHITCH1 == LOW && SHITCH2 == LOW){
Apagar(LG);
Apagar(LB);
Encender(LR); 
delay (500);
Apagar(LR);
Encender(LG); 
delay (500);
Apagar(LG); 
Encender(LB); 
delay (500);
Apagar(LB); 
}
}
