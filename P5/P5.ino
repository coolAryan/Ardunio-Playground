
   

#include <QTRSensors.h>
#define NUM_SENSORS 4      // number of sensors used

#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low

#define EMITTER_PIN  2
/**************
 * Sensor 3 = pin7, Sensor 4 = pin5, Sensor 5 = pin4, Sensor 6 = pin3
 */
QTRSensorsRC qtrrc((unsigned char[]) {7,5,4,3} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN); /// Make sure to put the pin# as shown above of the arduino to the sensor within the curly bracket
unsigned int sensorValues[NUM_SENSORS]; // list of sensors
void setup()
{
// Calibration code starts here
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
  Serial.println();
 Serial.println();
 delay(1000);
}
void loop()
{
 // Sensor 3 = pin7, Sensor 4 = pin5, Sensor 5 = pin4, Sensor 6 = pin3
 unsigned int position = qtrrc.readLine(sensorValues);
  // down below is optional: Starts here unsigned char i = 0;
int line1 = sensorValues[i=1]; /// Value for sensor 4
int line2 = sensorValues[i=2]; /// Value for sensor 5
int line3 =  sensorValues[i=3]; //Value for sensor 6
int line4 = sensorValues[i]; // Value for sensor 3
// Ends here
 for (unsigned char i = 0; i < NUM_SENSORS; i++)
 {
    Serial.print(sensorValues[i]);
  Serial.print('\t');
  }
  Serial.println(); 

  /// uncommenct below if you want the position(optional)

 // Serial.println(position); 

  delay(250);
 }
