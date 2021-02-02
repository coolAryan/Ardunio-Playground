int sensor1=4;
int sensor2 = 7;

void setup() {
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  // put your setup code here, to run once:
Serial.begin(96000);
}

void loop() {
  // put your main code here, to run repeatedly:s
  Serial.print(digitalRead(sensor1));
   
}
