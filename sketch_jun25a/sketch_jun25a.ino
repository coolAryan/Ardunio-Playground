#include <QTRSensors.h>
#define NUM_SENSORS   8
#define TIMEOUT       2500
#define EMITTER_PIN   QTR_NO_EMITTER_PIN

QTRSensorsRC qtrrc((unsigned char[]) {2,3,4,5,6,7,8,9}, NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
unsigned int line_position = 0; // value from 0-7000 to indicate position of line between sensor 0 - 7



void setup()
{

  Serial.begin(9600);
  delay(2000);
  for (int i = 0; i <= 400; i++)  // begin calibration cycle to last about 2.5 seconds (100*25ms/call)
  {

    // auto calibration sweeping left/right, tune 'calSpeed' motor speed at declaration

   
    qtrrc.calibrate();       // reads all sensors with the define set 2500 microseconds (25 milliseconds) for sensor outputs to go low.
  }
  line_position = qtrrc.readLine(sensorValues);


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
  Serial.println("Calibration Complete");
  delay(1000);

}

void loop()
{
  // read calibrated sensor values and obtain a measure of the line position from 0 to 7000
  // To get raw sensor values, call:
   qtrrc.read(sensorValues); //instead of unsigned int position = qtrrc.readLine(sensorValues);
 // unsigned int line_position = qtrrc.readLine(sensorValues);

  //Serial.println(); // uncomment this line if you are using raw values
  Serial.print(line_position); // comment this line out if you are using raw values
  Serial.print("  ");
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
