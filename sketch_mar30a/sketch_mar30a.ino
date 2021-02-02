#include<Servo.h>
Servo ls_thigh;
Servo ls_knee;
Servo ls_ankle;
Servo rs_thigh;
Servo rs_knee;
Servo rs_ankle;
int servopos=0;



void setup() {
  ls_thigh.attach(3);
  ls_knee.attach(9);
  ls_ankle.attach(10);
  rs_thigh.attach(6);
  rs_knee.attach(5);
  rs_ankle.attach(11);
  // put your setup code here, to run once:

}

void loop() 
{
  for(servopos = 90; servopos < 90; servopos++)
   {
   ls_thigh.write(servopos);
   delay(10);
   }
     for(servopos = 90; servopos > 90; servopos--)
   {
   ls_thigh.write(servopos);
   delay(10);
   }
   for(servopos = 93; servopos < 93; servopos++)
   {
   rs_thigh.write(servopos);
   delay(10);
   }
    
    for(servopos = 93; servopos > 93; servopos--)
   {
   rs_thigh.write(servopos);
   delay(10);
   }
   for(servopos = 39; servopos < 40; servopos++)
   {
   rs_knee.write(servopos);
   delay(10);
   }
    
    for(servopos = 40; servopos > 39; servopos--)
   {
   rs_knee.write(servopos);
   delay(10);
   }
   for(servopos = 90; servopos < 90; servopos++)
   {
   ls_knee.write(servopos);
   delay(10);
   }
    
    for(servopos = 90; servopos > 90; servopos--)
   {
   ls_knee.write(servopos);
   delay(10);
   }
   
   
}
