#include <SoftwareSerial.h>
#include <Wire.h>
#include <PCF8574.h>
//Directivas
#define buzz 14
#define Expansor_HIGH LOW  
#define Expansor_LOW HIGH  
#define Peten 2
#define Izabal 3
#define Alta_Verapaz 4
#define Baja_Verapaz 5
#define Huehuetenango 6
#define Quiche 7
#define Zacapa 8
#define Chiquimula 9
#define El_Progreso 12
#define Jalapa 13
#define Jutiapa 15
#define Guatemala 16
#define Totonicapan 17
#define Solola 20
#define Quetzaltenango 21
#define San_Marcos 0
#define Retalhuleu 1
#define Escuintla 2
#define Chimaltenango 3
#define Sacatepequez 4
#define Suchitepequez 5
#define Santa_Rosa 6
PCF8574 expansor_PCF(0x27);
SoftwareSerial BT(10, 11); // RX, TX  
#define preguntas 22 //Cantidad de preguntas
#define temporizador 15 //Segundos Para Responder
//Variables
byte num_pregunta;  //Numero de pregunta
String respondiendo;
bool listo = false;  //Espera a que el Modulo BT este en linea e imprima la frase "Listo"
  //Para la Melodia
  #define Do 262
  #define Re 294
  #define Sol 392
  #define Lasos 466
  #define Si 494
//Funciones
int ruleta();  //Elije un numero de pregunta al azar (Nideah como se hace juas juas)
void responder();   //Muestra la pregunta en el BT espera respuesta y determina si es correcta o incorrecta
void incorrecta(); //La respuesta es incorrecta
void contador_temporizador();
void setup() {
  pinMode(Peten, OUTPUT); 
  pinMode(Izabal, OUTPUT);
  pinMode(Alta_Verapaz, OUTPUT);
  pinMode(Baja_Verapaz, OUTPUT);
  pinMode(Huehuetenango, OUTPUT);
  pinMode(Quiche, OUTPUT);
  pinMode(Zacapa, OUTPUT);
  pinMode(Chiquimula, OUTPUT);
  pinMode(El_Progreso, OUTPUT);
  pinMode(Jalapa, OUTPUT);
  pinMode(Jutiapa, OUTPUT);
  pinMode(Guatemala, OUTPUT);
  pinMode(Totonicapan, OUTPUT); 
  pinMode(Solola, OUTPUT);
  pinMode(Quetzaltenango, OUTPUT);
  Serial.begin(9600);
  BT.println("Comencemos... ¿Estas listo?");
}
void loop() {
  digitalWrite(Peten, HIGH);
  digitalWrite(Izabal, HIGH);
  digitalWrite(Alta_Verapaz, HIGH);
  digitalWrite(Baja_Verapaz, HIGH);
  digitalWrite(Huehuetenango, HIGH); 
  digitalWrite(Quiche, HIGH); 
  digitalWrite(Zacapa, HIGH);
  digitalWrite(Chiquimula, HIGH);
  digitalWrite(El_Progreso, HIGH);
  digitalWrite(Jalapa, HIGH);
  digitalWrite(Jutiapa, HIGH);
  digitalWrite(Guatemala, HIGH);
  digitalWrite(Totonicapan, HIGH);
  digitalWrite(Solola, HIGH);
  digitalWrite(Quetzaltenango, HIGH);
  expansor_PCF.write(San_Marcos, Expansor_LOW);
  expansor_PCF.write(Retalhuleu, Expansor_LOW);
  expansor_PCF.write(Escuintla, Expansor_LOW);
  expansor_PCF.write(Chimaltenango, Expansor_LOW);
  expansor_PCF.write(Sacatepequez, Expansor_LOW);
  expansor_PCF.write(Suchitepequez, Expansor_LOW);
  expansor_PCF.write(Santa_Rosa, Expansor_LOW);
  if(Serial.available()>0){
    String empezar = Serial.readStringUntil('\n');
  if ( empezar == String("Listo")){
  BT.println("Primera pregunta");
  listo = true;
    delay(100); } }
  if (listo == true){
  num_pregunta = random(0, 21);
  responder();
  delay(1000);
   BT.println();
  BT.println("Siguiente pregunta");}
  if(listo == false){
    if (listo == false){
  BT.println("Escribe Listo para iniciar");
  while(!Serial.available()){
    delay(10);}}}}
void responder(){
      if(num_pregunta == 0){
    BT.println("Cabecera departamental de Izabal");
    contador_temporizador();
      if(respondiendo == String("Puerto Barrios")){
        digitalWrite(Izabal, LOW);
        delay(5000);
        digitalWrite(Izabal, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 1 ){
    BT.println("Cabecera departamental de Zacapa");
    contador_temporizador();
      if(respondiendo == String("Zacapa")){
        digitalWrite(Zacapa, LOW);
        delay(5000);
        digitalWrite(Zacapa, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 2 ){
    BT.println("Cabecera departamental de Chiquimula");
    contador_temporizador();
      if(respondiendo == String("Chiquimula")){
        digitalWrite(Chiquimula, LOW);
        delay(5000);
        digitalWrite(Chiquimula, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 3 ){
    BT.println("Cabecera departamental de Jutiapa");
    contador_temporizador();
      if(respondiendo == String("Jutiapa")){
        digitalWrite(Jutiapa, LOW);
        delay(5000);
        digitalWrite(Jutiapa, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 4 ){
    BT.println("Cabecera departamental de Santa Rosa");
    contador_temporizador();
      if(respondiendo == String("Cuilapa")){
        expansor_PCF.write(6, Expansor_HIGH);
        delay(5000);
        expansor_PCF.write(6, Expansor_LOW);}
      else{
        incorrecta();}}
      if(num_pregunta == 5){
    BT.println("Cabecera departamental de Escuintla");
    contador_temporizador();
      if(respondiendo == String("Escuintla")){
        expansor_PCF.write(2, Expansor_HIGH);
        delay(5000);
        expansor_PCF.write(2, Expansor_LOW);}
      else{
        incorrecta();}}
      if(num_pregunta == 6 ){
    BT.println("Cabecera departamental de Suchitepéquez");
    contador_temporizador();
      if(respondiendo == String("Mazatenango")){
        expansor_PCF.write(5, Expansor_HIGH);
        delay(5000);
        expansor_PCF.write(5, Expansor_LOW);}
      else{
        incorrecta();}}
      if(num_pregunta == 7 ){
    BT.println("Cabecera departamental de Retalhuleu");
    contador_temporizador();
      if(respondiendo == String("Retalhuleu")){
        expansor_PCF.write(1, Expansor_HIGH);
        delay(5000);
        expansor_PCF.write(1, Expansor_LOW);}
      else{
        incorrecta();}}
      if(num_pregunta == 8 ){
    BT.println("Cabecera departamental de San Marcos");
    contador_temporizador();
      if(respondiendo == String("San Marcos")){
        expansor_PCF.write(0, Expansor_HIGH);
        delay(5000);
        expansor_PCF.write(0, Expansor_LOW);}
      else{
        incorrecta();}}
      if(num_pregunta == 9 ){
    BT.println("Cabecera departamental de Quetzaltenango");
    contador_temporizador();
      if(respondiendo == String("Quetzaltenango")){
        digitalWrite(Quetzaltenango, LOW);
        delay(5000);
        digitalWrite(Quetzaltenango, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 10 ){
    BT.println("Cabecera departamental de Sololá");
    contador_temporizador();
      if(respondiendo == String("Solola")){
        digitalWrite(Solola, LOW);
        delay(5000);
        digitalWrite(Solola, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 11 ){
    BT.println("Cabecera departamental de Chimaltenango");
    contador_temporizador();
      if(respondiendo == String("Chimaltenango")){
        expansor_PCF.write(3, Expansor_HIGH);
        delay(5000);
        expansor_PCF.write(3, Expansor_LOW);}
      else{
        incorrecta();}}
      if(num_pregunta == 12 ){
    BT.println("Cabecera departamental de Sacatepéquez");
    contador_temporizador();
      if(respondiendo == String("Antigua guatemala")){
        expansor_PCF.write(4, Expansor_HIGH);
        delay(5000);
        expansor_PCF.write(4, Expansor_LOW);}
      else{
        incorrecta();}}
      if(num_pregunta == 13 ){
    BT.println("Cabecera departamental de Guatemala");
    contador_temporizador();
      if(respondiendo == String("Guatemala")){
        digitalWrite(Guatemala, LOW);
        delay(5000);
        digitalWrite(Guatemala, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 14 ){
    BT.println("Cabecera departamental de Jalapa");
    contador_temporizador();
      if(respondiendo == String("Jalapa")){
        digitalWrite(Jalapa, LOW);
        delay(5000);
        digitalWrite(Jalapa, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 15 ){
    BT.println("Cabecera departamental de El progreso");
    contador_temporizador();
      if(respondiendo == String("Guastatoya")){
        digitalWrite(El_Progreso, LOW);
        delay(5000);
        digitalWrite(El_Progreso, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 16 ){
    BT.println("Cabecera departamental de Baja Verapaz");
    contador_temporizador();
      if(respondiendo == String("Salama")){
        digitalWrite(Baja_Verapaz, LOW);
        delay(5000);
        digitalWrite(Baja_Verapaz, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 17 ){
    BT.println("Cabecera departamental de Totonicapán");
    contador_temporizador();
      if(respondiendo == String("Totonicapan")){
        digitalWrite(Totonicapan, LOW);
        delay(5000);
        digitalWrite(Totonicapan, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 18){
    BT.println("Cabecera departamental de Huehuetenango");
    contador_temporizador();
      if(respondiendo == String("Huehuetenango")){  //Resuesta Correcta
        digitalWrite(Huehuetenango, LOW);
        delay(5000);
        digitalWrite(Huehuetenango, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 19){
    BT.println("Cabecera departamental de Quiché");
    contador_temporizador();
      if(respondiendo == String("Santa Cruz del Quiche")){   //Respuesta correcta
        digitalWrite(Quiche, LOW);
        delay(5000);
        digitalWrite(Quiche, HIGH);}
      else{
        incorrecta();}}
      if(num_pregunta == 20){
    BT.println("Cabecera departamental de Alta Verapaz");
    contador_temporizador();
      if(respondiendo == String("Coban")){    //Respuesta correcta
        digitalWrite(Alta_Verapaz, LOW);
        delay(5000);
        digitalWrite(Alta_Verapaz, HIGH);}
      else{
        incorrecta();}}
    if(num_pregunta == 21){
    BT.println("Cabecera departamental de Petén");
    contador_temporizador();
      if(respondiendo == String("Flores")){    //Respuesta correcta
        digitalWrite(Peten, LOW);
        delay(5000);
        digitalWrite(Peten, HIGH);}
      else{
        incorrecta();}}}
void contador_temporizador(){
  bool tiempo_agotado = false;
  int i = temporizador;
  while((!Serial.available()>0) && tiempo_agotado == false){
    Serial.print(i);
    Serial.print("...");
    delay(900);
    i--;
    if(i < 0){
      tiempo_agotado = true;
       BT.println();
      BT.println("Tiempo Agotado :( ");
      Serial.print("No hubo respuesta");
      }
    }
    BT.println();
    respondiendo = Serial.readStringUntil('\n');
    if(tiempo_agotado == false){
      BT.println("Respuesta recibida: " + respondiendo);}}
void incorrecta(){
  BT.println("Respuesta Incorrecta");
  tone(buzz, Re*2 ,500);
  delay(100);
  tone(buzz, Sol*2 ,500); 
  delay(200);
  tone(buzz, Sol*2 ,500);  
  delay(200);
  tone(buzz, Do*2 ,500); 
  delay(200);
  tone(buzz, Lasos*2 ,500); 
  delay(500);
  tone(buzz, Do*2,500);
  delay(100);
  tone(buzz, Si*2,500);  
  delay(100);
  delay(500);
    }
