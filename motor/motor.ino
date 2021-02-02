

int LM1=2;
int LM2=4;
int RM1=6;
int RM2=7;
int ENL=3;
int ENR=5;
//int

void setup() {
 

 pinMode(LM1,OUTPUT);
 pinMode(RM1,OUTPUT);
 pinMode(LM2,OUTPUT);
 pinMode(RM2,OUTPUT);
 pinMode(ENL,OUTPUT);
 pinMode(ENR,OUTPUT);
}

void loop() {
    
    digitalWrite(RM1,HIGH);
    digitalWrite(LM1,HIGH);
    digitalWrite(RM2,LOW);
    digitalWrite(LM2,LOW);
    analogWrite(ENL,400);
    analogWrite(ENR,100);
  // put your main code here, to run repeatedly:

}
