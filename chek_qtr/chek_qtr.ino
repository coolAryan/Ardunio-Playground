#define TIMEOUT 2500
int s[] = {2,4, 5, 6, 7, 8, 9,10};
int sensor[8];
 
void setup() {
  Serial.begin(9600);
  for (int i = 0; i <8; i++)
  { pinMode(s[i], INPUT);
  }
  
  
    // reads all sensors with the define set 2500 microseconds (25 milliseconds) for sensor outputs to go low.
  
}
void loop()
{
  int k;
  for (int l = 0; l <=TIMEOUT; l++)  // begin calibration cycle to last about 2.5 seconds (100*25ms/call)
  {
   
    for(int i=0;i<8;i++)
      {
        
        
        Serial.println(analogRead(s[i]));
      }
     /* for (int i = 0; i < 8; i++)
      {
        sensor[i] = map(s[i], 0, 2500, 0, 1000);
       // Serial.println(sensor[i]);
      }*/
  
  }
  }
