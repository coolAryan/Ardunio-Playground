#include<SoftwareSerial.h>
#include<Servo.h>

Servo servo;

// Pin diclaration
int LS1 = 3;
int LS2 = 4;
int RS2 = 7;
int RS1 = 8;
int LM1 = A4;
int LM2 = A5;
int RM1 = A6;
int RM2 = A7;
int ENL = 10;
int ENR = 9;
int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int but_lfr = 12;
int but_light = 13;
int but_height = 2;
int trigPin = 5;
int echoPin = 6;
char t;
int maxm = 0;


void setup() {
  Serial.begin(9600);
  //bt.begin(9600);
  pinMode(LS1, INPUT);
  pinMode(LS2, INPUT);
 // pinMode(FS, INPUT);
  pinMode(RS1, INPUT);
  pinMode(RS2, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(but_lfr, INPUT);
  pinMode(but_light, INPUT);
//  pinMode(but_bt, INPUT);
  pinMode(but_height, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(11);
  servo.write(90);

  digitalWrite(but_lfr,HIGH);
  digitalWrite(but_light,HIGH);
//  digitalWrite(but_bt,HIGH);
  digitalWrite(but_height,HIGH);
}
void left()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
}
void right()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
}
void Qright()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, HIGH);
}
void Qleft()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM2, LOW);
}

void forward()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
}
void stopp()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
}


float distance()
{ 
  float duration,dis;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  dis=(duration/2)*0.0343;
  //return dis;
  if (dis<25)
  {
    
    
    }
}



void LFR()
{
  while (1)
  {
    /*Serial.print(digitalRead(LS2));
    Serial.print("  ");
    Serial.print(digitalRead(LS1));
    Serial.print("  ");
    Serial.print(digitalRead(RS1));
    Serial.print("  ");
    Serial.println(digitalRead(RS2));
    Serial.print("  ");
//    Serial.println(digitalRead(FS));*/

    //1111

    if (digitalRead(LS2) == 1 && digitalRead(LS1) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
    {
      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      left();
    }
    //0110
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
    {
      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      left();
    }
    //1000
    else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0)
    {
      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      left();
    }
    //0001
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1)
    {
      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      right();
    }
    //0111
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      right();
    }
    //1110
    else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      left();
    }
    //1100
    else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      left();
    }
    //0011
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      Qright();
    }
    //0101
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      right();
    }
    //1010
    else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      right();
    }
    //0100
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      left();
    }
    //0010
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      right();
    }
    //1011
    else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
    {
      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      Qleft();
    }
    //1101
    else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      Qright();
    }
    //1001
    else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      right();
    }
    //0000
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      forward();
    }
    //00000
   /* else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(FS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      Qleft();
    }*/
  }
}


void light()
{//int maxm = 0;
    analogRead(ldr1);
    Serial.print(ldr1);
    Serial.print("\t");
    analogRead(ldr2);
    Serial.print(ldr2);
     Serial.print("\t");
    analogRead(ldr3);
    Serial.print(ldr3);
     Serial.print("\t");
    if (ldr1 > maxm)
    {
      maxm = ldr1;
      forward();
    }
    if (ldr2 > maxm)
    {
      maxm = ldr2;
      right();
    }
    if (ldr3 > maxm)

    {
      maxm = ldr3;
      left();
    }
    Serial.print(maxm);
     Serial.print("\n");
  
  }


void bluetooth()
{
  if(Serial.available())  
  {
    t = Serial.read();
    if (t == 'F')
    {
      forward();
    }
    else if (t == 'R')
    {
      right();
    }
    else if (t == 'L')
    {
      left();
    }
    else if (t == 'B')
    {
      Qright();
    }
    else
    {
      stopp();
    }
  }
}



/*void height() {
  
  for(int i=90;i>=0;i--)
  {
    diff = US_measure;
    servo.write(i);
    delay(500);
    US_measure=distance();
    diff-=US_measure;
    if(diff>=8)
    {
      
      break;
    }
  }
   for(int i=0;i<=90;i++)
  {
    diff = US_measure;
    servo.write(i);
    delay(500);
    US_measure=distance();
    diff-=US_measure;
    if(diff>=8)
    {
      break;
    }
  }
  
  
  for(int i=90;i<=180;i++)
  {
    diff = US_measure;
    servo.write(i);
    delay(500);
    US_measure=distance();
    diff-=US_measure;
    if(diff>=8)
    {
      break;
    }
  }
}
*/

void loop()
{
  if(digitalRead(but_lfr)==LOW)
  {
    LFR();
  }
  else if(digitalRead(but_light)==LOW)
  {
    light();
  }
 
 else if(digitalRead(but_height)==LOW)
  {
    height();
  }
   else
  {
    bluetooth();
  }
}
