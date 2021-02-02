int LS1 =3;
int LS2 =2 ;
int RS1 = A1;
int RS2 =A0 ;
int FS = 4;
int FLS = A3;
int MS = A2;
int LM1=4;
int LM2=5;
int RM1=8;
int RM2=7;
int ENL=6;
int ENR=9;


void setup() {
  pinMode(ENL,OUTPUT);  //Set control pins to be outputs
  pinMode(ENR,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
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
void loop() 
{
  forward();
       analogWrite(ENR,255);
       analogWrite(ENL,255);
              delay(1000);
  left();
       analogWrite(ENR,255);
       analogWrite(ENL,255);
              delay(1000);
              right();
       analogWrite(ENR,255);
       analogWrite(ENL,255);
              delay(1000);
              Qright();
       analogWrite(ENR,255);
       analogWrite(ENL,255);
              delay(1000);
              Qleft();
       analogWrite(ENR,255);
       analogWrite(ENL,255);
              delay(1000);
              
              
                           
  // put your main code here, to run repeatedly:

}
