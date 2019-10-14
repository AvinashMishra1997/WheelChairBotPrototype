#include <SoftwareSerial.h>
#define LS 2
#define RS 3     

SoftwareSerial BT(10, 11);
String readdata;

int trig=8;//
int echo=9;//
float T,D;//


void setup() {
 BT.begin(38400);
 Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);

}

void loop() { 
  while (BT.available()){
    digitalWrite(trig,LOW);
  delayMicroseconds(100);
  digitalWrite(trig,HIGH);
  
  delayMicroseconds(100);
  digitalWrite(trig,LOW);
  T=pulseIn(echo,HIGH);
  D=0.0343*T/2;
  if(D<20)
  {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7, LOW);
    delay(3000);
    continue;
    
  }
  char c = BT.read();
  readdata += c;
  }
  if (readdata.length() > 0) {
    //Serial.println(readdata);
    

  if(readdata == "1")
  {
   
    digitalWrite (4, LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7, HIGH);
    delay(100);
  }
 

  else if(readdata == "2")
  {
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7, LOW);
    delay(100);
  }

  else if (readdata == "3")
  {
    
    digitalWrite (4,LOW);
    digitalWrite (5,HIGH);
    digitalWrite (6,LOW);
    digitalWrite (7,LOW);
    delay (100);
   
  }

 else if ( readdata == "4")
 {
   
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (100);
 }
 else if (readdata == "5")
 {
   
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (100);
 }
else if(readdata == "6"){
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    Serial.println(digitalRead(LS));//////
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7, LOW);
    delay(100);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
    Serial.println(digitalRead(LS));//////
    digitalWrite (4,LOW);
    digitalWrite (5,HIGH);
    digitalWrite (6,LOW);
    digitalWrite (7,LOW);
    delay (100);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
    Serial.println(digitalRead(LS));//////
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (100);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(100);
  }
}
 


readdata="";}}
