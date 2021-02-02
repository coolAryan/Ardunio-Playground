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
//int

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
}
void forward()
{
digitalWrite(LM1,HIGH);
digitalWrite(RM1,HIGH);
digitalWrite(LM2,LOW);
digitalWrite(RM2,LOW);  
}
void loop() {
  if(digitalRead(LS2)==1 ) 
  {
    
    analogWrite(ENL,50);
    analogWrite(ENR,50);
    forward();
  }
  // put your main code here, to run repeatedly:

}
