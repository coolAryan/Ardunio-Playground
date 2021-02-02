#include<SoftwareSerial.h>
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
int but_bt = 2;
int trigPin = 5;
int echoPin = 6;
float duration, distance;
char t;
int buttonState = 0;

void setup() {
  // bt.begin(9600);
  pinMode(LS1, INPUT);
  pinMode(LS2, INPUT);
  pinMode(RS1, INPUT);
  pinMode(RS2, INPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
  pinMode(but_light, INPUT);
  pinMode(but_bt, INPUT);
  pinMode(but_lfr, INPUT);
  Serial.begin(9600);
  //pinMode(MS,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:
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
/*void distance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * .0343;
}*/
void loop() {
    int buttonState1 = digitalRead(12);
 int  buttonState2 = digitalRead(13);
   int buttonState3 = digitalRead(2);

  Serial.print(digitalRead(LS2));
  Serial.print("  ");
  Serial.print(digitalRead(LS1));
  Serial.print("  ");
  Serial.print(digitalRead(RS1));
  Serial.print("  ");
  Serial.println(digitalRead(RS2));
  Serial.print("  ");
//  Serial.println(digitalRead(FS));

  if (buttonState1 == HIGH)
  {
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
    else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(FS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0)
    {

      analogWrite(ENL, 50);
      analogWrite(ENR, 50);
      Qleft();
    }
  }


  else if (buttonstate2 = HIGH)
  {
    int maxm = 0;
    analogRead(ldr1);
    analogRead(ldr2);
    analogRead(ldr3);
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
  }




  else if (buttonState3 == HIGH)
  {
    if (Serial.available())
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









  /*distance();
  if (distance > 20)
  {
    forward();
  }
  else if (distance <= 20)
  {
    Qright();
  }*/

}
