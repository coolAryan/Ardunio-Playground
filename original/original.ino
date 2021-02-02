#define TIMEOUT 2500
int sensor[] = {A0,A1,A2,A3,A4,A5,A6,A7};
int s[8];
int sum=0;
int avg=0;
int minm=1023;
int maxm=0;
int ENL=3;  //PWM control for motor outputs 1 and 2 is on digital pin 10  (Left motor)
int ENR=11;  //PWM control for motor outputs 3 and 4 is on digital pin 11  (Right motor)
int L1=15;  
int L2=14;
int R1=12; 
int R2=13 ;
int calSpeed = 40; 
int pos;
void setup() 
{
  Serial.begin(9600);
  for (int i =0; i <8; i++)
  { pinMode(sensor[i], INPUT);
  }
  
  for (int l = 0; l <=400; l++)  // begin calibration cycle to last about 2.5 seconds (100*25ms/call)
  {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
    analogWrite(ENL, calSpeed);
    digitalWrite(R2, HIGH);
    digitalWrite(R1, LOW);
    analogWrite(ENR, calSpeed);
    for (int i = 0; i < 8; i++)
      {
        s[i]=analogRead(sensor[i]);
      }
      for (int i = 0; i < 8; i++)
      {
        s[i] = map(sensor[i], 0,1023, 0, 1000);
        //Serial.println(s[i]);
      /
     // delay(5000);
    // reads all sensors with the define set 2500 microseconds (25 milliseconds) for sensor outputs to go low.
  }
    for(int i=0;i<8;i++)
    {
      avg=(i*s[i]*1000)+avg;
      sum=s[i]+sum;
    }
       pos=avg/sum;
     // Serial.print(pos);
  digitalWrite(ENL, 0);  // stop right motor first which kinda helps avoid over run
  digitalWrite(ENR, 0);  
  for (int i = 0; i <8; i++)
  {
    
    if(s[i]<minm)
    {
     minm=s[i]; 
     }
  }
  Serial.print(minm);
  Serial.print(' ');
  Serial.println();
  
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i<8; i++)
  {
    
    if(s[i]>maxm)
    {
     maxm=s[i]; 
     }
  }
  Serial.print(maxm);
    Serial.print(' ');
  Serial.println();
  Serial.println();
  Serial.println("Calibration Complete");
  delay(1000);
  

}

void loop()
{
   //unsigned int pos=avg/sum;
    Serial.print(pos);
    Serial.print("  ");
     Serial.print(s[0]);
     Serial.print("  ");
     Serial.print(s[1]);
     Serial.print("  ");
     Serial.print(s[2]);
     Serial.print("  ");
     Serial.print(s[3]);
     Serial.print("  ");
     Serial.print(s[4]);
     Serial.print("  ");
     Serial.print(s[5]);
     Serial.print("  ");
     Serial.print(s[6]);
     Serial.print("  ");
     Serial.print(s[7]);
     Serial.print("\n");
}
