#include <Adafruit_AM2315.h>

#include <Adafruit_Sensor.h>

#include<NewPing.h>
#include<DHT.h>
#define DHT TYPE DHT 22
int echoPin=13;
int TrigPin=10;
int max=400;
int DHT pin=7;
float duration,distance,hum,temp,soundspeed,spdcm;
int iteration=10;
NewPing sonar(TrigPin,echoPin,max);
DHT dht(DHT PIN,DHT TYPE);



void setup() {
  Serial.begin(9600);
  dht.begin();
  
  // put your setup code here, to run once:

}

void loop() {
  delay(2000);
 
  hum=dht.readHumidity();
  temp=dht.readTemperature();
  Serial.print("Humidity= ");
  Serial.print(hum);
  Serial.print("temperature= ");
  Serial.print(temp);
  soundspeed=331.4+(0.606*temp)+(0.0124*hum);
  spdcm=soundspeed/10000;
   duration=sonar.ping_median(iteration);
  distance=(duration/2)*spdcm;
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
