/*
  analogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/analogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A0);
  /*int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);
  int sensorValue5 = analogRead(A4);
  int sensorValue6 = analogRead(A5);
  int sensorValue7 = analogRead(A6);
  int sensorValue8 = analogRead(A7);*/
  // print out the value you read:
  Serial.print("sens1=\t");
  Serial.print(sensorValue1);
  Serial.print("\n");
  /*Serial.print("sens2=\t");
  Serial.print(sensorValue2);
  Serial.print("\n");
  Serial.print("sens3=\t");
  Serial.print(sensorValue3);
  Serial.print("\n");
  Serial.print("sens4=\t");
  Serial.print(sensorValue4);
  Serial.print("\n");
  Serial.print("sens5=\t");
  Serial.print(sensorValue5);
  Serial.print("\n");
  Serial.print("sens6=\t");
  Serial.print(sensorValue6);
  Serial.print("\n");
  Serial.print("sens7=\t");
  Serial.print(sensorValue7);
  Serial.print("\n");
  Serial.print("sens8=\t");
  Serial.print(sensorValue8);*/
  delay(1);        // delay in between reads for stability
}
