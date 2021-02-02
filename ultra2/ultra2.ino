

#include<NewPing.h>
int echoPin=13;
int TrigPin=10;
int max=400;
float duration,distance;
NewPing sonar(TrigPin,echoPin,max);



void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  distance=sonar.ping_cm();
  
 Serial.print("Distance= ");
  if(distance>=400 || distance<=2)
  {
    Serial.print("out of range");
    }
    else
    {
     Serial.print(distance);
    Serial.println("cm");
    }
    delay(500);  
    
  
  // put your main code here, to run repeatedly:

}
