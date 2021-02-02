#include <QTRSensors.h>  
#define NUM_SENSORS   8 
#define TIMEOUT       2500  
#define EMITTER_PIN   QTR_NO_EMITTER_PIN  
QTRSensorsRC qtrrc((unsigned char[]) {3, 4, 5, 6, 7, 8, 9, 10},NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];
unsigned int line_position=0;

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
}

void loop()
{
  line_position = qtrrc.readLine(sensorValues);
   
   Serial.print("\n");
  
   Serial.print(sensorValues[0]);
    Serial.print("\t");
    Serial.print(sensorValues[1]);
    Serial.print("\t");
    Serial.print(sensorValues[2]);
    Serial.print("\t");
    Serial.print(sensorValues[3]);
    Serial.print("\t");
    Serial.print(sensorValues[4]);
    Serial.print("\t");
Serial.print(sensorValues[5]);
    Serial.print("\t");
Serial.print(sensorValues[6]);
    Serial.print("\t");
   Serial.print(sensorValues[7]);
    
   Serial.print("\n");       
}
