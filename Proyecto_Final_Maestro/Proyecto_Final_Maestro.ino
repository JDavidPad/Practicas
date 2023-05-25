/*
   Centro Educativo Tecnico Laboral Kinal
   Quinto perito en electronica
   EB5AM
   Taller de electronica digital y reparacion de computadoras
   Nombres: Edgar Leonel Ramirez Estrada 2019410(coordinador)
            Álvaro Anzueto Rodas 2019733
            Joué David Padilla Morataya 2022074
            Juan Manuel Sebastián Ixen Coy 2019519
            
   Fecha: 25/05/2023
   Proyecto Final del Segundo Bimestre
   Proyecto: casa domotizada    Grupo No.7
*/

//Se incluyen las librerias a utilizar//
#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Key.h>
#include <Keypad.h>

//Se le da nombres a las funciones de entrada salida//
#define salida(pin) pinMode(pin,OUTPUT)
#define entrada(pin) pinMode(pin,INPUT)

//USO DEL LCD//
LiquidCrystal_I2C lcd_casa(0x27, 16, 2);

//Dibujo para focos apagados//
byte apagado[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000,
  B11111,
  B01110
};
//Dibujo para focos encendidos//
byte encendido[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000,
  B11111,
  B01110
};
//dibujo para puerta abierta//
byte abierto[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001
};
//dibujo para puerta cerrada//
byte cerrado[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11101,
  B11111,
  B11111,
  B11111
};
//dibujo para cuando se detecta el carro//
byte Hombre[] = {
  B11111,
  B11111,
  B01110,
  B11111,
  B11111,
  B01110,
  B11011,
  B11011
};
//dibujo para cuando no se detecte el carro//
byte esqueleto[] = {
  B00000,
  B00000,
  B01110,
  B10101,
  B00100,
  B01110,
  B01010,
  B01010
};
//dibujo para temperatura calida//
byte taza[] = {
  B00011,
  B11011,
  B11000,
  B00000,
  B01111,
  B11111,
  B11111,
  B01111
};
//dibujo para temperatura fría//
byte nieve[] = {
  B10100,
  B01000,
  B10100,
  B00000,
  B00000,
  B00101,
  B00010,
  B00101
};
//Teclado Matricial//
const byte FILAS = 4; // Son el numero de filas que se encuentran en el teclado matricial//
const byte COLUMNAS = 4; // Son el numero de columnas que se encuentran en el teclado matricial//

//Se realiza la matriz para utilizar el teclado matricial//
char tecladoCasa[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinesFilas[FILAS] = {9, 8, 7, 6}; // Pines conectados a las filas
byte pinesColumnas[COLUMNAS] = {5, 4, 3, 2}; // Pines conectados a las columnas

Keypad teclado = Keypad(makeKeymap(tecladoCasa), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

/////////////ServoMotor//
Servo puerta;          //
#define pin_servo 10   //
////////////////////////

#define rele_1  11  //Se indican en que pines se encontraran los reles//
#define rele_2  12
#define rele_3  13
#define rele_4  14
#define rele_5  15

bool Encendido_1 = false;   //Se realizan variales del estilo booleano para cada relé//
bool Encendido_2 = false;
bool Encendido_3 = false;
bool Encendido_4 = false;
bool Encendido_5 = false;

//instrucciones para arduino esclavo//
#define temperatura 16
bool lecturatemperatura;

#define parqueo 17
bool lecturaparqueo;

void setup() { //Se declaran entradas y salidas de los distintos pines//
  entrada(parqueo);
  entrada(temperatura);
  Serial.begin(9600);
  lcd_casa.init();//Se da inicio al LCD//
  lcd_casa.backlight();
  puerta.attach(pin_servo);//Se da inicio al ServoMotor//
  lcd_casa.setCursor(0, 0);
  lcd_casa.print("FOCO:");
  lcd_casa.createChar(0, apagado);  //Se crean los diversos caracteres que estaran en la visualización del LCD//
  lcd_casa.createChar(1, encendido);
  lcd_casa.createChar(2,Hombre);
  lcd_casa.createChar(3,esqueleto);
  lcd_casa.createChar(4,taza);
  lcd_casa.createChar(5,nieve);
  lcd_casa.createChar(6,cerrado);
  lcd_casa.createChar(7,abierto);
  lcd_casa.setCursor(0, 1);
  lcd_casa.print("DOOR:");
  lcd_casa.setCursor(7,1);
  lcd_casa.print("TEM:");
  lcd_casa.setCursor(13,1);
  lcd_casa.print("G:");
//Se declaran las entradas y salidas de los reles//  
  salida(rele_1); 
  salida(rele_2);
  salida(rele_3);
  salida(rele_4);
  salida(rele_5);
}

void loop() { //Se hace llamado de los voids//
  Control_casa();
  Pantalla();
  instrucciones_parqueo();
  instrucciones_temperatura();
}

//Se muestran las instrucciones de la temperatura que nos ayudaran con el arduino esclavo//
void instrucciones_temperatura(){
  lecturatemperatura=digitalRead(temperatura);
//Realizamos algunas operaciones las cuales nos ayudaran a controlar y regular la temperatura//
  if(lecturatemperatura == 0){
    lcd_casa.setCursor(10,1);
    lcd_casa.write(4);
  }
  if(lecturatemperatura==1){
    lcd_casa.setCursor(10,1);
    lcd_casa.write(5);
  }
}
//Se muestran las instrucciones del parqueo que nos ayudaran con el arduino esclavo//
void instrucciones_parqueo(){
  lecturaparqueo=digitalRead(parqueo);
//Se le dan instrucciones para que al momento de operar el ultrasonico pueda ver que se debe de realizar//
  if(lecturaparqueo == 0){
    lcd_casa.setCursor(15,1);
    lcd_casa.write(3);
  }
  if(lecturaparqueo==1){
    lcd_casa.setCursor(15,1);
    lcd_casa.write(2);
  }
}

//Este void es utilizado para todo el control del teclado matricial//
void Control_casa() {
  char tecladoCasa = teclado.getKey();

  if (tecladoCasa) {
    if (tecladoCasa == '1') {
      Encendido_1 = !Encendido_1; //Se le da un cambio de estado el cual como estaba como falso pase a verdadero//
      digitalWrite(rele_1, Encendido_1 ? HIGH : LOW); // Atravez de los cambios de estado podremos indicar en que momento estara encendido y apagado el rele//
    }
    if (tecladoCasa == '2') {
      Encendido_2 = !Encendido_2;
      digitalWrite(rele_2, Encendido_2 ? HIGH : LOW);
    }
    if (tecladoCasa == '3') {
      Encendido_3 = !Encendido_3;
      digitalWrite(rele_3, Encendido_3 ? HIGH : LOW);
    }
    if (tecladoCasa == 'A') {
      Encendido_4 = !Encendido_4;
      digitalWrite(rele_4, Encendido_4 ? HIGH : LOW);
    }
    if (tecladoCasa == '4') {
      Encendido_5 = !Encendido_5;
      digitalWrite(rele_5, Encendido_5 ? HIGH : LOW);
    }
    if(tecladoCasa == '5'){ //Con este boton podremos cerrar la puerta//
      puerta.write(0);
      lcd_casa.setCursor(5,1);
      lcd_casa.write(6);
    }
    if(tecladoCasa=='6'){ //Con este boton podremos abrir la puerta//
      puerta.write(90);
      lcd_casa.setCursor(5,1);
      lcd_casa.write(7);
    }
  }
}

void Pantalla() { //Declaramos los caracteres de encendido y apagado para cada boton conectado a los reles//
  if (Encendido_1 == LOW) {
    lcd_casa.setCursor(6, 0);
    lcd_casa.write(0);
  }
  else if (Encendido_1 == HIGH) {
    lcd_casa.setCursor(6, 0);
    lcd_casa.write(1);
  }
  if (Encendido_2 == LOW) {
    lcd_casa.setCursor(8, 0);
    lcd_casa.write(0);
  }
  else if (Encendido_2 == HIGH) {
    lcd_casa.setCursor(8, 0);
    lcd_casa.write(1);
  }
  if (Encendido_3 == LOW) {
    lcd_casa.setCursor(10, 0);
    lcd_casa.write(0);
  }
  else if (Encendido_3 == HIGH) {
    lcd_casa.setCursor(10, 0);
    lcd_casa.write(1);
  }
  if (Encendido_4 == LOW) {
    lcd_casa.setCursor(12, 0);
    lcd_casa.write(0);
  }
  else if (Encendido_4 == HIGH) {
    lcd_casa.setCursor(12, 0);
    lcd_casa.write(1);
  }
  if (Encendido_5 == LOW) {
    lcd_casa.setCursor(14, 0);
    lcd_casa.write(0);
  }
  else if (Encendido_5 == HIGH) {
    lcd_casa.setCursor(14, 0);
    lcd_casa.write(1);
}
}
