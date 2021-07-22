
#include <NewPing.h>
#include<Servo.h>
#define TRIGGER_PIN A3
#define ECHO_PIN A2
#define MAX_DISTANCE 300
int a=9,b=10,c=11,d=12,e=8,EN1=5,EN2=6;
String voice;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo;
void setup() {
  Serial.begin(9600);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
  pinMode(e,INPUT);
  myservo.attach(7);
myservo.write(90);
}

void loop() {
   int distance = sonar.ping_cm();
if(Serial.available()>0) {
  voice="";
  delay(2);
  voice = Serial.readString();
  delay(2);
  Serial.println(voice);



if(voice == "left")
{
 left();
}
else if (voice == "right") {
 right();
}

else if (voice == "stop"){
 STOP();
  
}
}
while(voice == "forward") {
  forward();
}
while(voice == "backward") {
  backward();
}

}
void forward(){
  int distance = sonar.ping_cm();
  
 if(distance>0 && distance < 11){
  Serial.println(distance);
  STOP();
  voice="";
 }
 else 
 {
  Serial.println(distance);
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
analogWrite(EN1,130);
analogWrite(EN2,130); 
 }
}
void backward(){
  int IRSENSOR=digitalRead(e);
  Serial.println(IRSENSOR);
   if(IRSENSOR == 0) {
STOP();
voice="";
      }
      else {
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
analogWrite(EN1,130);
analogWrite(EN2,130); 
  }
}
void left(){
   myservo.write(180);
  delay(500);
  myservo.write(90);
  delay(500);
 digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
analogWrite(EN1,128); 
analogWrite(EN2,128); 
delay(500);
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
}
void right(){
   myservo.write(0);
  delay(500);
  myservo.write(90);
  delay(500);
digitalWrite(a,HIGH);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
analogWrite(EN1,128); 
analogWrite(EN2,128); 
delay(500);
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);

}
void STOP(){
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
 
}
