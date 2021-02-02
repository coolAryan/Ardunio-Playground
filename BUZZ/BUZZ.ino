#include<Servo.h>
Servo servo;
int trigPin=7;
int echoPin=6;
int buzz=8;
int LM1 = A4;
int LM2 = A5;
int RM1 = A6;
int RM2 = A7;
float duration,distance;
int i=0;
void setup() 
{
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(buzz,OUTPUT);
 servo.attach(11);
 servo.write(90);
 delay(500);
}
void Qright()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, HIGH);
}


void loop() 
{
 digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

duration=pulseIn(echoPin,HIGH);
distance=(duration/2)*.0343;
int t=distance;
//Serial.print("distance= ");

Serial.print(t);

Serial.print("\t");
delay(2000);
digitalWrite(buzz,LOW);
/*if(distance<25)
{
  digitalWrite(buzz,HIGH);*/
  for(i=90;i>=20;i--)
{
  
  
  int t=distance;
  servo.write(i);
  
   diff=;
  Serial.print(base);
  Serial.print("\n");
  delay(200);
}
for(i=20;i>=90;i--)
{
  servo.write(i);
   delay(5);
}
  //delay(100);
 // Serial.println("beep");
  Qright();
  
}
