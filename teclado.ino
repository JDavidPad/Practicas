/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Blumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#include <Keypad.h>
#define pina 2
#define pinb 3 
#define pinc 4
#define pind 5
#define pine 6
#define pinf 7
#define ping 8
#define Entrada(pin) pinMode (pin, INPUT)
#define Salida(pin) pinMode (pin, OUTPUT)
#define Encender(pin) digitalWrite (pin, HIGH)
#define Apagar(pin) digitalWrite (pin, LOW)
#define filas_teclado 4   
#define columnas_teclado 4 
#define f1_teclado 2 
#define f2_teclado 3 
#define f3_teclado 4  
#define f4_teclado 5  
#define c1_teclado 6  
#define c2_teclado 7  
#define c3_teclado 8  
#define c4_teclado 9  
char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
void setup() {
Salida (pina);
Salida (pinb);
Salida (pinc);
Salida (pind);
Salida (pine);
Salida (pinf);
Salida (ping);
Entrada(f1_teclado);
Entrada(f2_teclado);
Entrada(f3_teclado);
Entrada(f4_teclado);
Entrada(c1_teclado);
Entrada(c2_teclado);
Entrada(c3_teclado);
Entrada(c4_teclado);
}

void loop() {

}
