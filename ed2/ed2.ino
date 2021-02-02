#include <QTRSensors.h>
#define TIMEOUT   2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN  2     //emitterPin is the Arduino digital pin that controls whether the IR LEDs are on or off. Emitter is controlled by digital pin 2
#define NUM_SENSORS 8         //number of sensors used
QTRSensorsRC qtrrc((unsigned char[]) {2,3,4,5,6,7,8,9} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
void setup() {

 for (int i = 0; i < 400; i++)  // make the calibration take about 10 seconds
  {
    qtrrc.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
  }
  digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we are through with calibration
  // print the calibration minimum values measured when emitters were on
  Serial.begin(9600);
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  // put your setup code here, to run once:

}
void loop() {
  // Sensor 3 = pin7, Sensor 4 = pin5, Sensor 5 = pin4, Sensor 6 = pin3
 unsigned int position = qtrrc.readLine(sensorValues);
  // down below is optional: Starts here
Serial.print(sensorValues[0]);
  Serial.print("  ");
  Serial.print(sensorValues[1]);
  Serial.print("  ");
  Serial.print(sensorValues[2]);
  Serial.print("  ");
  Serial.print(sensorValues[3]);
   Serial.print("  ");
  Serial.print(sensorValues[4]);
  Serial.print("  ");
  Serial.print(sensorValues[5]);
     Serial.print("  ");
  Serial.print(sensorValues[6]);
   Serial.print("  ");
  Serial.print(sensorValues[7]);
  Serial.print("\n");

}
