
int s0 = 9, s1 = 10;
int digits[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 1},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1, 1}
};
void setup()
{
  for (int l = 2; l < 11; l++)
  {
    pinMode(l, 1);
  }

}
void loop()
{
  for (int count = 0; count < 100; count++)
  {
    for (int t = 0; t < 100; t++) 
    {
      digitalWrite(s0, 0); digitalWrite(s1, 1);
      for (int i = 0; i < 8; i++) 
      {
        digitalWrite(i + 2, digits[count/10][i]);
        //delayMicroseconds(5);
      }
      delay(5);
      digitalWrite(s0, 1); digitalWrite(s1, 0);
      for (int i = 0; i < 8; i++) 
      {
        digitalWrite(i + 2, digits[count%10][i]);
        //delayMicroseconds(5);
      }
      delay(5);
    }
  }

}



//
//
