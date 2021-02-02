#include<SoftwareSerial.h>
SoftwareSerial bt (0,1);
int LS1=5;
int LS2=4;
int FS=12 ;
int RS2=3;
int RS1=2;
int LM1=9;
int LM2=10;
int RM1=8;
int RM2=7;
int ENL=11;
int ENR=6;


void left()
{
digitalWrite(LM1,LOW);
digitalWrite(RM1,HIGH);
digitalWrite(LM2,LOW);
digitalWrite(RM2,LOW);  
}
void right()
{
digitalWrite(LM1,HIGH);
digitalWrite(RM1,LOW);
digitalWrite(LM2,LOW);
digitalWrite(RM2,LOW);  
}
void Qright()
{
digitalWrite(LM1,HIGH);
digitalWrite(RM1,LOW);
digitalWrite(LM2,LOW);
digitalWrite(RM2,HIGH);  
}
void Qleft()
{
digitalWrite(LM1,LOW);
digitalWrite(RM1,HIGH);
digitalWrite(LM2,HIGH);
digitalWrite(RM2,LOW);  
}

void forward()
{
digitalWrite(LM1,HIGH);
digitalWrite(RM1,HIGH);
digitalWrite(LM2,LOW);
digitalWrite(RM2,LOW);  
}
void stopp()
{
digitalWrite(LM1,LOW);
digitalWrite(RM1,LOW);
digitalWrite(LM2,LOW);
digitalWrite(RM2,LOW);  
}

void setup() {
  Serial.begin(9600);
  bt.begin(9600);

}

void loop() {
  if (bt.available())
  {
   char t=bt.read();
     if(t=='F')
     {
      forward();
     }
else if(t=='R')
      {
        right();
      }
else if(t=='L')
      {
          left();
      }
else if(t=='B')
      {
        Qright();
      }
   else
      {
         stopp();
      }
      Serial.print(t);
  }
  if (Serial.available())
  {
    bt.println(Serial.readString());

  }

}
