int EN=A0;
int MS1=11;
int MS2=12; 
 
 
void setup() {
  // put your setup code here, to run once:
  pinMode(EN,OUTPUT);
  pinMode(MS1,OUTPUT);
  pinMode(MS2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(EN,HIGH);
  //digitalWrite(EN,HIGH);
  digitalWrite(MS1,HIGH);
  digitalWrite(MS2,LOW);
  delay(700);
  digitalWrite(MS1,LOW);
  digitalWrite(MS2,LOW);
  delay(70);
  
}
