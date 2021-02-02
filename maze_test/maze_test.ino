int LS1 =A1;
int LS2 = A0;
int RS1 = A3;
int RS2 = A4;
int FS = A5;
int FLS = 2;
int MS = A2;
int RM1 = 12;
int RM2 = 13;
int ENR = 10;
int ENL = 11;
int LM1 = 8;
int LM2 = 9;
char a[200];
char b[150];
int i, j;
int stop1 = 4;
int stop2 = 4;
int k[200];
int switch_flag ;
int dryrun_switch = 0;
int actualrun_switch = 1;
int path_length;
int count;
int not_the_shortest;
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
    
  pinMode(RM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
  pinMode(dryrun_switch, INPUT);
  pinMode(actualrun_switch, INPUT);
 
  digitalWrite(dryrun_switch,1);
  digitalWrite(actualrun_switch,1);
  
  
}

void loop()
{

  int dryrun = digitalRead(dryrun_switch);
  int actualrun = digitalRead( actualrun_switch) ;
   

  if ( dryrun == 0 && actualrun == 1)
  {
    switch_flag = 1;
    stop1 = 0;

  }
 else if ( dryrun == 1 && actualrun == 0)
  {
    switch_flag = 2;
    stop2 = 0;
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

  if (not_the_shortest == 1)
  {
    count = 0;
    while(j>n)
    {
      if (k[j] == 'L' && k[j + 1] == 'B' && k[j + 2] == 'L') //LBL
      {
        b[count] = 'S';
        count++;
        j=j+3;


      }
      else if (k[j] == 'R' && k[j + 1] == 'B' && k[j + 2] == 'L') //RBL
      {
        b[count] = 'B';
        count++;
        j=j+3;

      }

      else if (k[j] == 'L' && k[j + 1] == 'B' && k[j + 2] == 'R') //LBR
      {
        b[count] = 'B';
        count++;
        j=j+3;

      }

      else if (k[j ] == 'L' && k[j + 1] == 'B' && k[j + 2] == 'S') //LBS
      {
        b[count] = 'R';
        count++;
        j=j+3;
      }
      else if (k[j ] == 'S' && k[j + 1] == 'B' && k[j + 2] == 'L') //SBL
      {
        b[count] = 'R';
        count++;
        j=j+3;

      }
      else if ( k[j] != 'S' && k[j + 1] != 'B' && k[j+2] != 'S')//SBS
      {
        b[count] ='B';
        count++;
        j=j+3;
      }
      else{
        
        b[count]=k[j];
        count++;
        j++;
        }
    }
    for (i = 0; b[i] != '\0'; i++)
    {
      k[i] = b[i];
    }
    short_path_algorithm();
  }

  else
  {
    not_the_shortest=0;
    for (i = 0; i < path_length; i++)
    {
      if (k[i] == 'B')
      {
        not_the_shortest = 1;
      }
    }
    if (not_the_shortest == 1)
    {
      short_path_algorithm();
    }
  }

}
void IR1()
{
  i = 0;
  //000111
  if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'L';
    i = i + 1;
  }
   //000110
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'L';
    i = i + 1;
  }
     //001110
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
    //001111
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
    //000000
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'L';
    i = i + 1;
  }
      //000001
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'L';
    i = i + 1;
  }
      //000010
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 1 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'L';
    i = i + 1;
  }
      //000011
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 1 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'L';
    i = i + 1;
  }
  
      //10011
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
  
      //100001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BR();
    a[i] = 'R';
    i = i + 1;
  }
  
      //100000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    fwd();
    a[i] = 'S';
    i = i + 1;
  }
  
      //01111
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1  )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  
      //11011
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    fwd();
  }
  
      //11110
  else if(digitalRead(LS1) == 1&& digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
  
      //110000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    fwd();
    a[i] = 'S';
    i = i + 1;
  }
        //110001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BR();
    a[i] = 'R';
    i = i + 1;
  }
        //111110
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    fwd();
  }
         //111111
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
    a[i] = 'B';
    i = i + 1;
  }
         //111000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
         //111001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 1)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BR();
    a[i] = 'R';
    i = i + 1;
  }
         //111110
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
    //0000001
   if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0&& digitalRead(FLS)==1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    stop();
    a[i] = 'T';
    i = i + 1;
  stop1 = 1;


    for (i = 0; a[i] != '\0'; i++)
    {
      k[i] = a[i];
      path_length = i;

    }

    short_path_algorithm();



  }


}



void IR2()
{
  
  j=0;
  
  //000111
  if (digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    if(b[j]=='L')
    {
    BL();
    j++;
    }
    
  }
   //000110
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
     if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
     if (b[j] == 'S')
    {
      fwd();
      j = j + 1;
    }
    
   
  }
     //001110
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
    //001111
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    if(b[j]=='L')
    {
    BL();
    j++;
    }
  }
    //000000 0
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0 &&digitalRead(FLS)==0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
         if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
     if (b[j] == 'S')
    {
      fwd();
      j = j + 1;
    }
    if(b[j]=='R')
    {
      BR();
      j=j+1;
      }
    }
    
  }
      //000001
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    
      if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
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
    
  }
      //000010
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 1 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    
      if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
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
   
  }
      //000011
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 1 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    if(b[j]=='L')
    {
    BL();
    j++;
    }
  }
  
      //10011
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
  
      //100001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    if(b[j]=='R')
    {
    BR();
    j++;
    }
  
  }
  
      //100000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
      if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
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
   
  }
  
      //01111
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1  )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TL();
  }
  
      //11011
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    fwd();
  }
  
      //11110
  else if(digitalRead(LS1) == 1&& digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
  
      //110000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
      if (b[j] == 'L')
    {
      BL();
      j = j + 1;
    }
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
    
  }
        //110001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    if(b[j]=='R')
    {
    BR();
    j++;
    }
   
  }
        //111110
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    fwd();
  }
         //111111
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 1 && digitalRead(RS2) == 1 &&digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    if(b[j]=='L')
    {
    BL();
    j++;
    }
    
  }
         //111000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
         //111001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 1)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    if(b[j]=='R')
    {
    BR();
    j++;
    }
   
  }
         //111110
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    TR();
  }
    //0000001
   if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0&& digitalRead(RS1) == 0 && digitalRead(RS2) == 0 &&digitalRead(FS) == 0&& digitalRead(FLS)==1 )
  {
    analogWrite(ENL, 55);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    stop();
  stop2 = 1;
  }
