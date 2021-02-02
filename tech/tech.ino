
static char path[100], cpy[100], shortest[30];
int i = 1;
int x, y = 0;
int MS=1;
int ES=0;
int LS1 = 5;
int LS2 = 4;
int FS = 12 ;
int RS2 = 3;
int RS1 = 2;
int LM1 = 9;
int LM2 = 10;
int RM1 = 8;
int RM2 = 7;
int ENL = 11;
int ENR = 6;
//int
void setup() {
  pinMode(LS1, INPUT);
  pinMode(MS, INPUT);
  pinMode(ES, INPUT);
  pinMode(LS2, INPUT);
  pinMode(RS1, INPUT);
  pinMode(RS2, INPUT);
  pinMode(FS, INPUT);
  pinMode(MS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
  Serial.begin(9600);
  //pinMode(MS,INPUT);
  // put your setup code here, to run once:
}
void left()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
}
void right()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
}
void back()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, HIGH);
}
void forward()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
}
void stop()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);


}
void loop()
{
  Serial.print(digitalRead(LS2));
  Serial.print("  ");
  Serial.print(digitalRead(LS1));
  Serial.print("  ");
  Serial.print(digitalRead(RS1));
  Serial.print("  ");
  Serial.println(digitalRead(RS2));
  Serial.print("  ");
  Serial.println(digitalRead(FS));
  path[0] = 'S';
  //straight
  if (digitalRead(LS2) == 1 && digitalRead(LS1) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {

    analogWrite(ENL, 80);
    analogWrite(ENR, 80);
    forward();

  }
  //|-
  else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0)
  {
    analogWrite(ENL, 80);
    analogWrite(ENR, 80);
    forward();
    path[i] = 'S';
    i++;
  }
  //right
  else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1)
  {
    analogWrite(ENL, 80);
    analogWrite(ENR, 80);
    right();
    path[i] = 'R';
    i++;
  }
  //U
  else if (digitalRead(LS2) == 1 && digitalRead(LS1) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1)
  {
    analogWrite(ENL, 80);
    analogWrite(ENR, 80);
    back();
    path[i] = 'B';
    i++;
  }
  // -| & LEFT
  else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && (digitalRead(FS) == 1 || digitalRead(FS) == 0))
  {
    analogWrite(ENL, 80);
    analogWrite(ENR, 80);
    left();
    path[i] = 'L';
    i++;
  }
  //T &4WAY
  else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && (digitalRead(FS) == 1  || digitalRead(FS) == 0))
  {
    analogWrite(ENL, 80);
    analogWrite(ENR, 80);
    left();
    path[i] = 'L';
    i++;
  }
  else if (digitalRead(LS2) == 0 && digitalRead(LS1) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 && digitalRead(ES) == 0)
  {
    analogWrite(ENL, 80);
    analogWrite(ENR, 80);
    stop();
  }
  for (int j = 0; j <= i; j++)
  {
    cpy[j] = path[j]; 
    Serial.print(cpy[j]);
  }
  for ( x = 1; x < i; x++)
  {
    if (cpy[x - 1] == 'L' && cpy[x] == 'B' && cpy[x + 1] == 'L') //LBL
    {
      shortest[y] = 'S';
      y++;
    }
    if (cpy[x - 1] == 'R' && cpy[x] == 'B' && cpy[x + 1] == 'L') //RBL
    {
      shortest[y] = 'B';
      y++;
    }

    if (cpy[x - 1] == 'L' && cpy[x] == 'B' && cpy[x + 1] == 'R') //LBR
    {
      shortest[y] = 'B';
      y++;
    }

    if (cpy[x - 1] == 'L' && cpy[x] == 'B' && cpy[x + 1] == 'S') //LBS
    {
      shortest[y] = 'R';
      y++;
    }
    if (cpy[x - 1] == 'S' && cpy[x] == 'B' && cpy[x + 1] == 'L') //SBL
    {
      shortest[y] = 'R';
      y++;
    }
    if (cpy[x - 1] == 'S' && cpy[x] == 'B' && cpy[x + 1] == 'S') //SBS
    {
      shortest[y] = 'B';
      y++;
    }
    
  }
  /*for (int k = 0; k < y; k++)
  {
    Serial.print(shortest[k]);
    if (shortest[k] == 'L')
    {
      left();
    }
    if (shortest[k] == 'R')
    {
      right();
    }
    if (shortest[k] == 'B')
    {
      back();
    }
    if (shortest[k] == 'S')
    {
      forward();
    }
  }*/

}
