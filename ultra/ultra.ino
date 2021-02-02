int echoPin=3;
int TrigPin=2;
int LM1=6;
int RM1=8;
int LM2=7;
int RM2=9;
float duration,distance;
void setup() {

pinMode(LM1,OUTPUT);
pinMode(LM2,OUTPUT);
pinMode(RM1,OUTPUT);
pinMode(RM2,OUTPUT);

  Serial.begin(9600);
  pinMode(echoPin,INPUT);
   pinMode(TrigPin,OUTPUT);
  // put your setup code here, to run once:

}
void forward()
{
  digitalWrite(LM1,1);
  digitalWrite(LM2,0);
  digitalWrite(RM1,1);
  digitalWrite(RM2,0);
}
void backward()
{
  digitalWrite(LM1,0);
  digitalWrite(LM2,1);
  digitalWrite(RM1,0);
  digitalWrite(RM2,1);
}
void left()
{
  digitalWrite(LM1,0);
  digitalWrite(LM2,0);
  digitalWrite(RM1,1);
  digitalWrite(RM2,0);
}
void right()
{
  digitalWrite(LM1,1);
  digitalWrite(LM2,0);
  digitalWrite(RM1,0);
  digitalWrite(RM2,0);
}

void loop() {
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)*0.0343;
  Serial.print("Distance= ");
  Serial.print(distance);
  delay(100);
  Serial.print("\n");
     if(distance<15) 
    {
      backward();
      Serial.println("backward");
    }
    else if(distance>16 &&distance<40 )
   {
    forward();
    Serial.println("forward");
    
    }
    
  
  // put your main code here, to run repeatedly:

}
