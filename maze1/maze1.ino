int LS1 = 4;
int LS2 = 5;
int RS1 = 6;
int RS2 = 7;
int FS = 3;
int FLS = 1;
int MS = 2;
int RM1 = 10;
int RM2 = 11;
int ENR = 12;
int ENL = 13;
int LM1 = 8;
int LM2 = 9;
char a[200];
char b[150];
int i, j, n, t;
int task;
int stop1 = 4;
int stop2 = 4;
int k[3];
int switch_flag ;
int dryrun_switch = A1;
int actualrun_switch = A2;




void fwd()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);

}

void back()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM2, HIGH);
}

void stop()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);
}

void TL()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);

}


void TR()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, LOW);

}

void BR()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, HIGH);

}

void BL()
{
  digitalWrite(LM1, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM2, LOW);

}

void setup() {
  pinMode(LS1, INPUT);
  pinMode(LS2, INPUT);
  pinMode(RS1, INPUT);
  pinMode(RS2, INPUT);
  pinMode(FS, INPUT);
  pinMode(FLS, INPUT);
  pinMode(MS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
  pinMode(dryrun_switch, INPUT);
  pinMode(actualrun_switch, INPUT);
}

void loop()
{

  int dryrun = digitalRead(dryrun_switch);
  int actualrun = digitalRead( actualrun_switch) ;

  if ( dryrun == 1 && actualrun == 0)
  {
    switch_flag = 1;
    stop1 == 0;

  }
  if ( dryrun == 0 && actualrun == 1)
  {
    switch_flag = 2;
    stop2 == 0;
  }


  if ( switch_flag == 1 && stop1 == 0)
  {

    IR1();

  }

  if ( switch_flag == 2 && stop2 == 0)
  {

    IR2();

  }


}
// 0 - MEANS
// 1 - MEANS WHITE


void short_path_algorithm()
{
  for (i = 0; a[i] != '\0' ; i++)
  {
    if (a[i] == 'B')
    {
      not_the_shortest = 1;
    }

  }
  if (not_the_shortest == 1)
  {
    for (j = 0 ; j < i; j++)
    {
      if (k[j-1] == 'L' && k[j] == 'B' && k[j+1] == 'L') //LBL
      {
        a[j] = 'S';
        j++;


      }
      if (k[j-1] == 'R' && k[j] == 'B' && k[j+1] == 'L') //RBL
      {
        a[j] = 'B';
        j++;

      }

      if (k[j-1] == 'L' && k[j] == 'B' && k[j+1] == 'R') //LBR
      {
        a[j] = 'B';
        j++;

      }

      if (k[j-1] == 'L' && k[j] == 'B' && k[j+1] == 'S') //LBS
      {
        a[j] = 'R';
        j++;
      }
      if (k[j-1] == 'S' && k[j] == 'B' && k[j+1] == 'L') //SBL
      {
        a[j] = 'R';
        j++

      }
    }
  }


  



}



void IR1()
{
  i = 0;
  //1000
  if (digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //0100
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 65);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 65);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //0010
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 65);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 65);     // RIGHT MOTOR SPEED (0-254)
    BR();
  }
  //0001
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BR();
  }

  //1010
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  //1001
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  //0110
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  //0101
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }

  //1110
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //1011
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
  //1101
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  //0111
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
  //00001
  if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 &&  digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    fwd();

  }
  //000000
  if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {

    analogWrite(ENL, 60);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'B';
    i = i + 1;


  }
  //001000
  if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {

    analogWrite(ENL, 60);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    fwd();

  }


  //1100
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'L';
    i = i + 1;
  }

  //00110

  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BR();
    a[i] = 'R';
    i = i + 1;
  }
  //00111

  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    fwd();
    a[i] = 'S';
    i = i + 1;
  }

  //111100
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&  digitalRead(FLS) == 0 && digitalRead(MS) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'L';
    i = i + 1;

  }

  //1111111      Ending Box Case
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1  &&  digitalRead(FS) == 1  &&  digitalRead(FLS) == 1 &&  digitalRead(MS) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    stop();
    a[i] = 'T';
    stop1 = 1;

    

    short_path_algorithm();


    i = 0;
    j = 0;
    while (i < 200)
    {
      if (a[i] != 'B')
      {
        b[j] = a[i];
        i = i + 1;
        j = j + 1;
      }

      else if (a[i] == 'B')
      {
        k[0] = b[j - 1];
        k[1] = a[i];
        k[2] = a[i + 1];
        fn();
      }
    }
  }

}



void IR2()
{
  if (digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //0100
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 65);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 65);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //0010
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 65);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 65);     // RIGHT MOTOR SPEED (0-254)
    BR();
  }
  //0001
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BR();
  }

  //1010
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  //1001
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  //0110
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  //0101
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }

  //1110
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //1011
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
  //1101
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  //0111
  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
  //00001
  if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)


    if (b[j] == 'S')
    {
      fwd();
      j = j + 1;
    }

    if (b[j] == 'R')
    {
      BR();
      j = j + 1;
    }

    if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
  }


  //1100
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    if (b[j] == 'S')
    {
      fwd();
      j = j + 1;
    }

    if (b[j] == 'R')
    {
      BR();
      j = j + 1;
    }

    if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
  }

  //00110

  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    if (b[j] == 'S')
    {
      fwd();
      j = j + 1;
    }

    if (b[j] == 'R')
    {
      BR();
      j = j + 1;
    }

    if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
  }
  //00111

  else if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    if (b[j] == 'S')
    {
      fwd();
      j = j + 1;
    }

    if (b[j] == 'R')
    {
      BR();
      j = j + 1;
    }

    if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
  }

  //111100
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&  digitalRead(FLS) == 0 && digitalRead(MS) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    if (b[j] == 'S')
    {
      fwd();
      j = j + 1;
    }

    if (b[j] == 'R')
    {
      BR();
      j = j + 1;
    }

    if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
  }


  //1111111      Ending Box Case
  else if (digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1  &&  digitalRead(FS) == 1  &&  digitalRead(FLS) == 1 &&  digitalRead(MS) == 1 )
  {
    analogWrite(ENL, 60);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 60);     // RIGHT MOTOR SPEED (0-254)
    stop();
    a[i] = 'T';
    stop2 = 1;

  }
}
