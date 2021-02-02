
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int servopos = 0;

void setup()
{

  servo3.attach(9);
 
  
}

void loop()
{
   for(servopos = 0; servopos < 180; servopos++)
   {
   servo3.write(servopos);
   delay(10);
   }
   for(servopos = 180; servopos > 0; servopos--)
   {
   servo3.write(servopos);
   delay(10);
   }
   
}
