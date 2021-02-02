String readString;
#include <Servo.h> 
Servo myservo;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);  //the pin for the servo control 
  Serial.println("servo-test"); // so I can keep track of what is loaded
}

void loop()
{
  for(int i=0;i<180;i++)
  {
 myservo.write(360);
 delay(10);
}
 for(int i=180;i>0;i--)
  {
 myservo.write(360);
 delay(10);
}



}
