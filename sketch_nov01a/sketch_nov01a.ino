int x1 = 3;
int x2 = 5;
int y1 =6;
int y2 = 9;
void setup() {
  // put your setup code here, to run once:
pinMode(x1,OUTPUT);
pinMode(x2,OUTPUT);
pinMode(y1,OUTPUT);
pinMode(y2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(x1,HIGH);
digitalWrite(x2,LOW);
digitalWrite(y1,HIGH);
digitalWrite(y2,LOW);
}
