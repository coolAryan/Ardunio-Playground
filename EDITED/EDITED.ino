#include <QTRSensors.h>
#define TIMEOUT   2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN  2     //emitterPin is the Arduino digital pin that controls whether the IR LEDs are on or off. Emitter is controlled by digital pin 2
#define NUM_SENSORS 8         //number of sensors used
QTRSensorsRC qtrrc((unsigned char[]) {A7,A6,A5,A4,A3,A2,A1,A0} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN);
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
  // put your main code here, to run repeatedly:

unsigned int sensors[8];
int position = qtrrc.readLine(sensors);
Serial.println(position);
 Serial.print("  ");
Serial.print(sensorValues[0]);
  Serial.print("  ");
  Serial.println(sensorValues[7]);
   Serial.print("\n");

}
//get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position
