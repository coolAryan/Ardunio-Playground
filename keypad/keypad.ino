
char Keys[4][4] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
int col[4] = {2, 3, 4, 5};
int row[4] = {6, 7, 8, 9};
int c;
char getkey()
{
  for ( c = 0; c < 4; c++)
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(col[i], 1);
      digitalWrite(row[i], 1);
    }
    digitalWrite(col[c], 0);
    for (int r = 0; r < 4; r++)
    {
      if (digitalRead(row[r]) == 0)
      {
        while (digitalRead(row[r]) == 0);
        return Keys[r][c];
      }
    }
  }
  return '\0';

}
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 4; i++)
  {
    pinMode(row[i], 0);
    pinMode(col[i], 1);
  }

}
void loop()
{


  char k = getkey();
  if (k != '\0')
  {
    Serial.println(k);
    //lcd.print(k);
  }
}
