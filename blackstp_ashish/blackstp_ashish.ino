int LS=5;
int FS=6;
int MS=4;
int RS=3;
int LM1=10;
int LM2=11;
int RM1=8;
int RM2=7;
int ENL=9;
int ENR=11;
//int

void setup() {
  pinMode(LS,INPUT);
  pinMode(RS,INPUT);
 pinMode(MS,INPUT);
 pinMode(FS,INPUT);
 pinMode(LM1,OUTPUT);
 pinMode(RM1,OUTPUT);
 pinMode(LM2,OUTPUT);
 pinMode(RM2,OUTPUT);
 pinMode(ENL,OUTPUT);
 pinMode(ENR,OUTPUT); 
 //pinMode(MS,INPUT);
  // put your setup code here, to run once:

}
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
void Qleft()
{
digitalWrite(LM1,HIGH);
digitalWrite(RM1,LOW);
digitalWrite(LM2,LOW);
digitalWrite(RM2,HIGH);  
}
void Qright()
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
void loop() {

  //111
  if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==1 && digitalRead(FS)==0)
  {
    left();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
  }
  //000
 else if(digitalRead(LS)==0 &&digitalRead(MS)==0 && digitalRead(RS)==0 && digitalRead(FS)==0)
  {
    left();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
  }
  else if(digitalRead(LS)==0 &&digitalRead(MS)==0 && digitalRead(RS)==0 && digitalRead(FS)==1)
  {
    forward();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
  }
  //110
  else if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==0)
  {
    left();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
  }
  //101
  else if(digitalRead(LS)==1 &&digitalRead(MS)==0 && digitalRead(RS)==1)
  {
    left();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
  }
  //011
  else if(digitalRead(LS)==0 &&digitalRead(MS)==1 && digitalRead(RS)==1)
  {
    right();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
  }
  //001
  else if(digitalRead(LS)==0 &&digitalRead(MS)==0 && digitalRead(RS)==1)
  {
    right();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
  }
  //100
  else if(digitalRead(LS)==1 &&digitalRead(MS)==0 && digitalRead(RS)==0)
  {
    left();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
  }
  else if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==1 && digitalRead(FS)==1)
  {
    
    Qleft();
    analogWrite(ENL,150);
    analogWrite(ENR,150);
    
  }
  //010
  else if(digitalRead(LS)==0 && digitalRead(RS)==0)
  {
    forward();
    analogWrite(ENL,120);
    analogWrite(ENR,120);
  }
  

}
  
