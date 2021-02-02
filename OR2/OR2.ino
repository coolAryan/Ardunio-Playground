const int S[] = {A0, A1, A2, A3, A4, A5, A6, A7};
int sensor_value[8];
int sensorMin =1023;
int sensorMax=0;
unsigned int SUM1;
unsigned int SUM2;
unsigned int LINE;
void setup()
{
  Serial.begin(9600);
  /*for (int i = 0; i < 8; i++)
  { pinMode(S[i], INPUT);
  }*/
 Serial.println("CALIBRATION START");
  SENCAL();
  Serial.println("CALIBRATION DONE");
Serial.print("S1");
Serial.print("\t");
Serial.print("S2");
Serial.print("\t");
Serial.print("S3");
Serial.print("\t");
Serial.print("S4");
Serial.print("\t");
Serial.print("S5");
Serial.print("\t");
Serial.print("S6");
Serial.print("\t");
Serial.print("S7");
Serial.print("\t");
Serial.print("S8");
Serial.print("\t");
Serial.print("SUM1");
Serial.print("\t");
Serial.print("\t");
Serial.print("SUM2");
Serial.print("\t");
Serial.print("LINE");
Serial.print("\n");
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
 
  /*LINE = SUM1 / SUM2;
  Serial.print(SUM1);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print(SUM2);
  Serial.print("\t");
  Serial.print(LINE);
  //Serial.print("\n");*/

  Serial.print("\n");
}
void SVAL1()
{
  sensor_value[0]= analogRead(S[0]);
  sensor_value[0]= map(sensor_value[0], sensorMin, sensorMax, 0, 1000);
  sensor_value[0]= constrain(sensor_value[0], 0, 1000);
  sensor_value[0]=sensor_value[0]/100;
  Serial.print(sensor_value[0]);
}
void SVAL2()
{
  sensor_value[1]= analogRead(S[1]);
  sensor_value[1]= map(sensor_value[1], sensorMin, sensorMax, 0, 1000);
  sensor_value[1]= constrain(sensor_value[1], 0, 1000);
  sensor_value[1]=sensor_value[1]/100;
  Serial.print(sensor_value[1]);
}
void SVAL3()
{
  sensor_value[2] = analogRead(S[2]);
  sensor_value[2] = map(sensor_value[2], sensorMin, sensorMax, 0, 1000);
  sensor_value[2] = constrain(sensor_value[2], 0, 1000);
  sensor_value[2]=sensor_value[2]/100;
  Serial.print(sensor_value[2]);
}
void SVAL4()
{
  sensor_value[3] = analogRead(S[3]);
  sensor_value[3] = map(sensor_value[3], sensorMin, sensorMax, 0, 1000);
  sensor_value[3] = constrain(sensor_value[3], 0, 1000);
  sensor_value[3]=sensor_value[3]/100;
  Serial.print(sensor_value[3]);
}
void SVAL5()
{
  sensor_value[4] = analogRead(S[4]);
  sensor_value[4] = map(sensor_value[4], sensorMin, sensorMax, 0, 1000);
  sensor_value[4] = constrain(sensor_value[4], 0, 1000);
  sensor_value[4]=sensor_value[4]/100;
  Serial.print(sensor_value[4]);
}
void SVAL6()
{
  sensor_value[5] = analogRead(S[5]);
  sensor_value[5] = map(sensor_value[5], sensorMin, sensorMax, 0, 1000);
  sensor_value[5] = constrain(sensor_value[5], 0, 1000);
  sensor_value[5]=sensor_value[5]/100;
  Serial.print(sensor_value[5]);

}
void SVAL7()
{
   sensor_value[6] = analogRead(S[6]);
  sensor_value[6] = map(sensor_value[6], sensorMin, sensorMax, 0, 1000);
  sensor_value[6] = constrain(sensor_value[6], 0, 1000);
  sensor_value[6]=sensor_value[6]/100;
  Serial.print(sensor_value[6]);

}
void SVAL8()
{
  sensor_value[7] = analogRead(S[7]);
  sensor_value[7] = map(sensor_value[7], sensorMin, sensorMax, 0, 1000);
  sensor_value[7] = constrain(sensor_value[7], 0, 1000);
  sensor_value[7]=sensor_value[7]/100;
  Serial.print( sensor_value[7]);


}
void SENCAL()
{
  while (millis() < 5000)
  {
    for (int i = 0; i < 8; i++)
    {
      sensor_value[i] = analogRead(S[i]);
    }
    for (int r = 0; r < 8; r++)
    {
      if (sensor_value[r] > sensorMax)
      {
        sensorMax = sensor_value[r];
      }
    }
    for (int r = 0; r < 8; r++)
    {
      if (sensor_value[r] < sensorMin)
      {
        sensorMin = sensor_value[r];
      }
    }
  }
}
