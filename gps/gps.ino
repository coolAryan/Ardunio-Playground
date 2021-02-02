#include<SoftwareSerial.h>
SoftwareSerial gps (2, 3);




void setup() {
  Serial.begin(9600);
  gps.begin(9600);

}

void loop() {
  if (gps.available())
  {
    Serial.println(gps.readString());
  }
  if (Serial.available())
  {
    gps.println(Serial.readString());

  }

}
