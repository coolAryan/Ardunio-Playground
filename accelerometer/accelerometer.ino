#include<Servo.h>
Servo s;

int x=A2;
int y=A3;
int z=A4;

void setup() {
 Serial.begin(9600);
 s.attach(9);
 //pinMode(x,0);
//pinMode(y,0);
//pinMode(z,0);
}

void loop() {
  
  //Serial.print("x=");
 // Serial.print(analogRead(x));
  for(int k=0;k<180;k++)
  {s.write(k);
    }
    s.read();
    for(int k=180;k>0;k--)
  {s.write(k);
    }
    
  Serial.print("\n");
  delay(1000);
  /*Serial.print("y=");
  Serial.print(analogRead(y));
  Serial.print("\n");
 
  Serial.print("z=");
  Serial.print(analogRead(z));*/

}
