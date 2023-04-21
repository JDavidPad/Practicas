/*
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Blumno: Josué David Padilla Morataya
Seccion: A
Carne: 2022074
*/
#define TRIGGER 9 
#define ECO 11 
#define FOCO 13
long dis; 
int personas = -1;
  
void setup() {
  Serial.begin(9600);
  for(int i = 2; i <=8; i++){      
    pinMode(i,OUTPUT);
  } 
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(FOCO, OUTPUT);
  digitalWrite(TRIGGER, LOW);
}
void loop(){
  Medicion();
  personas_maximas();
}
int Medicion(){
  long Time; 
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIGGER, LOW);
  Time = pulseIn(ECO, HIGH);
  dis = Time/58; 
  delay(600);
  return dis;
}
void personas_maximas(){
  if(dis >= 2 && dis <=6){
    personas = personas + 1;
    Serial.println(personas);
        switch(personas){
        case 0:
        digitalWrite(FOCO, HIGH);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    delay(500);
    
      break;
    case 1:
    digitalWrite(FOCO, HIGH);
      digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500);
    break;
    case 2:   
    digitalWrite(FOCO, HIGH);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
      delay(500);
      break;
    case 3: 
    digitalWrite(FOCO, HIGH);
     digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  delay(500);
  break;
    case 4:
    digitalWrite(FOCO, HIGH);
      digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
     delay(500);
     break;
    case 5:
    
    digitalWrite(FOCO, HIGH);
      digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
     break;
    case 6:
    digitalWrite(FOCO, HIGH);
      digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
    break;
    case 7:
    digitalWrite(FOCO, HIGH);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    delay(500);
    break;
    case 8:
    
    digitalWrite(FOCO, HIGH);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
    break;
    
    case 9:
    digitalWrite(FOCO, HIGH);
      digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
break;
case 10:
Serial.println("La cantidad de personas ha alcanzado el Límite");
digitalWrite(FOCO, LOW);
delay(1000);
delay(1000);
delay(1000);
personas = -1;
break;
}
}
}
