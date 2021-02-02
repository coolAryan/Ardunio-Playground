#include<Servo.h>
Servo s;
int pos;
void setup() 
{
  s.attach(9);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int k=s.read();
  Serial.print(k);
  delay(1000);
  s.write(150);
  // put your main code here, to run repeatedly:

}
