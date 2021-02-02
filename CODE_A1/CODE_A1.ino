const int S1 = A0;
const int S2 = A1;
const int S3 = A2;
const int S4 = A3;
const int S5 = A4;
const int S6 = A5;
const int S7 = A6;
const int S8 = A7;

unsigned long int sensorValue1 = 0;
unsigned long int sensorValue2 = 0;
unsigned long int sensorValue3 = 0;
unsigned long int sensorValue4 = 0;
unsigned long int sensorValue5 = 0;
unsigned long int sensorValue6 = 0;
unsigned long int sensorValue7 = 0;
unsigned long int sensorValue8 = 0;

int sensorMin = 1023;
int sensorMax = 0;
int maxspeed = 400;
int rightmotorSpeed;
int leftmotorSpeed;
int motorspeed;
int ENL = 5; //PWM control for motor outputs 1 and 2 is on digital pin 10  (Left motor)
int ENR = 3; //PWM control for motor outputs 3 and 4 is on digital pin 11  (Right motor)
int L1 = 6;
int L2 = 7;
int R1 = 2 ;
int R2 = 4 ;
float Kp;
float Kd;
float error, lastError;

unsigned long int LINE;
unsigned long int SUM1;
unsigned long int SUM2 ;
void setup()
{
  Serial.begin(9600);
  Serial.println("CALIBRATION START");
  start();
 
  stopp();
  Serial.println("CALIBRATION DONE");
}
void start()
// auto calibration sweeping left/right, tune 'calSpeed' motor speed at declaration
{
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  analogWrite(ENL, 240);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, LOW);
  analogWrite(ENR, 240);
   SENCAL();
}
void stopp()
// auto calibration sweeping left/right, tune 'calSpeed' motor speed at declaration
{
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  analogWrite(ENL, 0);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, LOW);
  analogWrite(ENR, 0);
}

void loop()
{

  SVAL1();
  Serial.print("\t");
  SVAL2();
  Serial.print("\t");
  SVAL3();
  Serial.print("\t");
  SVAL4();
  Serial.print("\t");
  SVAL5();
  Serial.print("\t");
  SVAL6();
  Serial.print("\t");
  SVAL7();
  Serial.print("\t");
  SVAL8();
  Serial.print("\t");
  // Serial.print("\n");

  LINEPOSITION();
  Serial.print("\n");
  delay(100);
}

void SVAL1()
{
  sensorValue1 = analogRead(S1);
  sensorValue1 = map(sensorValue1, sensorMin, sensorMax, 0, 1000);
  //sensorValue1 = constrain(sensorValue1, 0, 1000);
  Serial.print( sensorValue1);
}
void SVAL2()
{
  sensorValue2 = analogRead(S2);
  sensorValue2 = map(sensorValue2, sensorMin, sensorMax, 0, 1000);
  //sensorValue2 = constrain(sensorValue2, 0, 1000);
  Serial.print(sensorValue2);
}
void SVAL3()
{
  sensorValue3 = analogRead(S3);
  sensorValue3 = map(sensorValue3, sensorMin, sensorMax, 0, 1000);
  //sensorValue3 = constrain(sensorValue3, 0, 1000);
  Serial.print(sensorValue3);
}
void SVAL4()
{
  sensorValue4 = analogRead(S4);
  sensorValue4 = map(sensorValue4, sensorMin, sensorMax, 0, 1000);
  //sensorValue4 = constrain(sensorValue4, 0, 1000);
  Serial.print(sensorValue4);
}
void SVAL5()
{
  sensorValue5 = analogRead(S5);
  sensorValue5 = map(sensorValue5, sensorMin, sensorMax, 0, 1000);
  // sensorValue5 = constrain(sensorValue5, 0, 1000);
  Serial.print(sensorValue5);
}
void SVAL6()
{
  sensorValue6 = analogRead(S6);
  sensorValue6 = map(sensorValue6, sensorMin, sensorMax, 0, 1000);
  //sensorValue6 = constrain(sensorValue6, 0, 1000);
  Serial.print(sensorValue6);
}
void SVAL7()
{
  sensorValue7 = analogRead(S7);
  sensorValue7 = map(sensorValue7, sensorMin, sensorMax, 0, 1000);
  //sensorValue7 = constrain(sensorValue7, 0, 1000);
  Serial.print(sensorValue7);
}
void SVAL8()
{
  sensorValue8 = analogRead(S8);
  sensorValue8 = map(sensorValue8, sensorMin, sensorMax, 0, 1000);
  //sensorValue8 = constrain(sensorValue8, 0, 1000);
  Serial.print(sensorValue8);
}
void LINEPOSITION()
{
  unsigned long int a = (0 * sensorValue1);
  // Serial.print(a);
  //Serial.print("\t");
  unsigned long int b = (1000 * sensorValue2);
  //Serial. print(b);
  //Serial.print("\t");
  unsigned long int c = (2 * 1000 * sensorValue3);
  //Serial.print(c);
  //Serial.print("\t");
  unsigned long int d = (3 * 1000 * sensorValue4);
  //Serial.print(d);
  //Serial.print("\t");
  unsigned long int e = (4 * 1000 * sensorValue5);
  //Serial.print(e);
  //Serial.print("\t");
  unsigned long int f = (5 * 1000 * sensorValue6);
  //Serial.print(f);
  //Serial.print("\t");
  unsigned long int g = (6 * 1000 * sensorValue7);
  //Serial.print(g);
  //Serial.print("\t");
  unsigned long int h = (7 * 1000 * sensorValue8);
  //Serial.println(h);
  //Serial.print("\t");
  SUM1 = (a + b + c + d + e + f + g + h);
  SUM2 = (sensorValue1 + sensorValue2 + sensorValue3 + sensorValue4 + sensorValue5 + sensorValue6 + sensorValue7 + sensorValue8);
  LINE = SUM1 / SUM2;
  /*Serial.print(SUM1);
    Serial.print("\t");
    Serial.print("\t");
    Serial.print(SUM2);
    Serial.print("\t");*/
  Serial.println(LINE);
  lastError = 0;

  while (1)
  {
    error = (float)LINE - 3500;
    // set the motor speed based on proportional and derivative PID terms
    // kp is the a floating-point proportional constant (maybe start with a value around 0.5)
    // kd is the floating-point derivative constant (maybe start with a value around 1)
    // note that when doing PID, it's very important you get your signs right, or else the
    // control loop will be unstable
    Kp = 3.5;
    Kd = 2;
    motorspeed = Kp * error + Kd * (error - lastError);
    lastError = error;
    //this codes limits the PV (motor speed pwm value)
    // limit PV to 55
    rightmotorSpeed = 200 + motorspeed;
    leftmotorSpeed = 200 - motorspeed;
    //set motor speeds
    set();
  }
}



void SENCAL()
{
  while (millis() < 5000)
  {
    /*sensorValue1 = analogRead(S1);
    sensorValue2 = analogRead(S2);
    sensorValue3 = analogRead(S3);
    sensorValue4 = analogRead(S4);
    sensorValue5 = analogRead(S5);
    sensorValue6 = analogRead(S6);
    sensorValue7 = analogRead(S7);
    sensorValue8 = analogRead(S8);*/
    //1
    // record the maximum sensor value
    if (sensorValue1 > sensorMax)
    {
      sensorMax = sensorValue1;
    }
    // record the minimum sensor value
    if (sensorValue1 < sensorMin)
    {
      sensorMin = sensorValue1;
    }
    //2
    // record the maximum sensor value
    if (sensorValue2 > sensorMax)
    {
      sensorMax = sensorValue2;
    }
    // record the minimum sensor value
    if (sensorValue2 < sensorMin)
    {
      sensorMin = sensorValue2;
    }
    //3
    // record the maximum sensor value
    if (sensorValue3 > sensorMax)
    {
      sensorMax = sensorValue3;
    }
    // record the minimum sensor value
    if (sensorValue3 < sensorMin)
    {
      sensorMin = sensorValue3;
    }
    //4
    // record the maximum sensor value
    if (sensorValue4 > sensorMax)
    {
      sensorMax = sensorValue4;
    }
    // record the minimum sensor value
    if (sensorValue4 < sensorMin)
    {
      sensorMin = sensorValue4;
    }
    //5
    // record the maximum sensor value
    if (sensorValue5 > sensorMax)
    {
      sensorMax = sensorValue5;
    }
    // record the minimum sensor value
    if (sensorValue5 < sensorMin)
    {
      sensorMin = sensorValue5;
    }
    //6
    // record the maximum sensor value
    if (sensorValue6 > sensorMax)
    {
      sensorMax = sensorValue6;
    }
    // record the minimum sensor value
    if (sensorValue6 < sensorMin)
    {
      sensorMin = sensorValue6;
    }
    //7
    // record the maximum sensor value
    if (sensorValue7 > sensorMax)
    {
      sensorMax = sensorValue7;
    }
    // record the minimum sensor value
    if (sensorValue7 < sensorMin)
    {
      sensorMin = sensorValue7;
    }
    //8
    // record the maximum sensor value
    if (sensorValue8 > sensorMax)
    {
      sensorMax = sensorValue8;
    }
    // record the minimum sensor value
    if (sensorValue8 < sensorMin)
    {
      sensorMin = sensorValue8;
    }
  }
}
void set()
{
  if (rightmotorSpeed > maxspeed)
  {
    rightmotorSpeed = maxspeed;
  }
  if (leftmotorSpeed > maxspeed)
  {
    leftmotorSpeed = maxspeed;
  }
  if (rightmotorSpeed < 0)
  {
    rightmotorSpeed = 0;
  }
  if (leftmotorSpeed < 0)
  {
    leftmotorSpeed = 0;
  }
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  analogWrite(ENL, leftmotorSpeed);
  digitalWrite(R2, LOW);
  digitalWrite(R1, HIGH);
  analogWrite(ENR, rightmotorSpeed);
}
