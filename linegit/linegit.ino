int LS1 =3;
int LS2 =2 ;
int RS1 = A1;
int RS2 =A0 ;
int FS = 4;
int MS = A2;
int RM1 = 8;
int RM2 = 9;
int ENR = 10;
int ENL = 11;
int LM1 = 12;
int LM2 = 13;


void setup() {
  pinMode(LS1,INPUT);
   pinMode(LS2,INPUT);
  pinMode(RS1,INPUT);
  pinMode(RS2,INPUT);
 pinMode(FS,INPUT);
 pinMode(LM1,OUTPUT);
 pinMode(RM1,OUTPUT);
 pinMode(LM2,OUTPUT);
 pinMode(RM2,OUTPUT);
 pinMode(ENL,OUTPUT);
 pinMode(ENR,OUTPUT);
  Serial.begin(9600);
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
void straight()
{
digitalWrite(LM1,HIGH);
digitalWrite(RM1,HIGH);
digitalWrite(LM2,LOW);
digitalWrite(RM2,LOW); 
}
void loop() {
      Serial.print(digitalRead(LS2));
     Serial.print("  ");
    Serial.print(digitalRead(LS1));
    Serial.print("  ");
    Serial.print(digitalRead(RS1));
    Serial.print("  ");
    Serial.println(digitalRead(RS2));
    Serial.print("  ");
    Serial.println(digitalRead(FS));
    //1111
  /*if(digitalRead(LS2)==1 &&digitalRead(LS1)==1 && digitalRead(RS1)==1 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    left();
 
  }
  //0110
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==1 && digitalRead(RS1)==1 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    left();
  }
  //1000
  else if(digitalRead(LS2)==1 &&digitalRead(LS1)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    left();
  }
  //0001
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    right();
  }
  //0111
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==1 && digitalRead(RS1)==1 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    right();
  }
  //1110
  else if(digitalRead(LS2)==1 &&digitalRead(LS1)==1 && digitalRead(RS1)==1 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    left();
  }
  //1100
  else if(digitalRead(LS2)==1 &&digitalRead(LS1)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    left();
  }
  //0011
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(RS1)==1 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    Qright();
  }
  //0101
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    right();
  }
  //1010
  else if(digitalRead(LS2)==1 &&digitalRead(LS1)==0 && digitalRead(RS1)==1 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    right();
  }
  //0100
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    left();
  }
  //0010
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(RS1)==1 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
   
    right();
  }
  //1011
  else if(digitalRead(LS2)==1 &&digitalRead(LS1)==0 && digitalRead(RS1)==1 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    Qright();
  }
   //1101
  else if(digitalRead(LS2)==1 &&digitalRead(LS1)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    Qleft();
  }
   //1001
  else if(digitalRead(LS2)==1 &&digitalRead(LS1)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    right();
  }
   //0000
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    forward();
  }
    //00000
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(FS)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    Qleft();
  }
  //cond for dash
   else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 &&  digitalRead(FS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    forward();
  }
  //cond for five sensor
  //00100
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0&& digitalRead(MS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
  }
 
  //00110
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0&& digitalRead(MS)==1 && digitalRead(RS1)==1 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
  }
  //01100
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==1 && digitalRead(MS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
  }
  //01110
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==1&& digitalRead(MS)==1 && digitalRead(RS1)==1 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
  }
 
  */
 //00000 0
   if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(MS)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0 && digitalRead(FS)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    straight();
  }
  //00000 1
   else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(MS)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0 && digitalRead(FS)==1)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    left();
  }
  //00100 
  
  else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(MS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    right();
  }
  
  //10000 
   else if(digitalRead(LS2)==1 &&digitalRead(LS1)==0 && digitalRead(MS)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    right();
  }
  
  //00100 
   else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(MS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    right();
  }
  
  //01000 
   else if(digitalRead(LS2)==0 &&digitalRead(LS1)==1 && digitalRead(MS)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    right();
  }
  
  //11000 0 
   else if(digitalRead(LS2)==1 &&digitalRead(LS1)==1 && digitalRead(MS)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0 && digitalRead(FS)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
  }
  
  //11000 1
   else if(digitalRead(LS2)==1 &&digitalRead(LS1)==1 && digitalRead(MS)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==0 && digitalRead(FS)==1)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    right();
  }
  
  //01100
   else if(digitalRead(LS2)==0 &&digitalRead(LS1)==1 && digitalRead(MS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
   left();
  }
  
  //10100
   else if(digitalRead(LS2)==1 &&digitalRead(LS1)==0 && digitalRead(MS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    right();
  }
  
  //11100  
   else if(digitalRead(LS2)==1 &&digitalRead(LS1)==1 && digitalRead(MS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0 )
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    right();
  }
  
  // 00001
   else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(MS)==0 && digitalRead(RS1)==0 && digitalRead(RS2)==1)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    left();
  }
  
  //11000 0 
   else if(digitalRead(LS2)==0 &&digitalRead(LS1)==0 && digitalRead(MS)==1 && digitalRead(RS1)==0 && digitalRead(RS2)==0 && digitalRead(FS)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
  }
}
 
 
 
 
 
 
 
 
 
 
