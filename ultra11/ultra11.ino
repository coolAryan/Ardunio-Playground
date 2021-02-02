int trigPin=10;
int echoPin=13;
float duration,distance;
void setup() 
{
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() 
{
 digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
}
duration=pulseIn(echoPin,HIGH);
distance=(duration/2)*.0343;
Serial.print("distance= ");
if(distance>=400 || distance<=2)
  {
  Serial.println("out of range");
   }
   else
   {
    Serial.print(distance);
    delay(500);
    
    }
    delay(500);
    }
    
