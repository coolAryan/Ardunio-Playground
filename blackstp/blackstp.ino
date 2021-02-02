
int LS1=5;
int LS2=;
int FS=2;
int MS=4;
int RS=3;
int LM1=9;
int LM2=10;
int RM1=8;
int RM2=7;
int ENL=11;
int ENR=6;
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

void forward()
{
digitalWrite(LM1,HIGH);
digitalWrite(RM1,HIGH);
digitalWrite(LM2,LOW);
digitalWrite(RM2,LOW);  
}
void loop() {

  //111
  if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==1 && digitalRead(FS)==0) //modified 
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    left();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  LEFT");
  }
   if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==0 && digitalRead(FS)==1)
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    left();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  LEFT");
  }
 /* else if(digitalRead(LS)==0 &&digitalRead(MS)==1 && digitalRead(RS)==0 && digitalRead(FS)==0)
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    left();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  LEFT");
  }*/
  
  //000
 else if(digitalRead(LS)==0 &&digitalRead(MS)==0 && digitalRead(RS)==0 && digitalRead(FS)==0)
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  FORWARD");
    
    
  }
/*  else if(digitalRead(LS)==0 &&digitalRead(MS)==0 && digitalRead(RS)==0 && digitalRead(FS)==1)
  {
    left();
    analogWrite(ENL,220);
    analogWrite(ENR,220);
  }*/
  //110
  else if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==0)
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    left();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  LEFT");
  }
  //101
  else if(digitalRead(LS)==1 &&digitalRead(MS)==0 && digitalRead(RS)==1)
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  FORWARD");
  }
  //011
  else if(digitalRead(LS)==0 &&digitalRead(MS)==1 && digitalRead(RS)==1)
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    right();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  RIGHT");
  }
  //001
  else if(digitalRead(LS)==0 &&digitalRead(MS)==0 && digitalRead(RS)==1)
  {
    right();
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  RIGHT");
  }
  //100
  else if(digitalRead(LS)==1 &&digitalRead(MS)==0 && digitalRead(RS)==0)
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    left();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  LEFT");
  }
  else if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==1 && digitalRead(FS)==1)
  {
    
   
    analogWrite(ENL,220);
    analogWrite(ENR,220);
     forward();
     Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  FORWARD");
    
  }
  //010
 else if(digitalRead(LS)==0 &&digitalRead(MS)==1 && digitalRead(RS)==0)
  {
    
    analogWrite(ENL,120);
    analogWrite(ENR,120);
    forward();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  FORWARD");
  }
 else if(digitalRead(LS)==0 &&digitalRead(MS)==1 && digitalRead(RS)==0 && digitalRead(FS)==1)
  {
    
    analogWrite(ENL,220);
    analogWrite(ENR,220);
    forward();
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  FORWARD");
  } 
 else if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==0 && digitalRead(FS)==0)//modified
  {
   
    analogWrite(ENL,100);
    analogWrite(ENR,200);
     Qleft();
     Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  QLEFT");
  } 
  else if(digitalRead(LS)==0 &&digitalRead(MS)==1 && digitalRead(RS)==1 && digitalRead(FS)==0)
  {
   
    analogWrite(ENL,250);
    analogWrite(ENR,100);
     Qright();
     Serial.println(LS,RS);
    Serial.println(MS,FS);
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  QRIGHT");
  } 
 else if(digitalRead(LS)==1 &&digitalRead(MS)==1 && digitalRead(RS)==0 && digitalRead(FS)==1)
  {
   
    analogWrite(ENL,250);
    analogWrite(ENR,100);
     Qright();
     Serial.println(LS,RS);
    Serial.println(MS,FS);
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  QRIGHT");
    
  }
  else if(digitalRead(LS)==0 &&digitalRead(MS)==1 && digitalRead(RS)==1 && digitalRead(FS)==1)
  {
   
    analogWrite(ENL,250);
    analogWrite(ENR,100);
     Qright();
     Serial.println(LS,RS);
    Serial.println(MS,FS);
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  QRIGHT");
    
  }
  else if(digitalRead(LS)==0 && digitalRead(RS)==1 && digitalRead(FS)==0)
  {
   
    analogWrite(ENL,220);
    analogWrite(ENR,100);
     Qright();
     Serial.println(LS,RS);
    Serial.println(MS,FS);
    Serial.println(digitalRead(LS));
     Serial.println("  ");
    Serial.println(digitalRead(MS));
    Serial.println("  ");
    Serial.println(digitalRead(RS));
    Serial.println("  ");
    Serial.println(digitalRead(FS));
    Serial.println("  QRIGHT");
    
  }
 
  
    
}
  
