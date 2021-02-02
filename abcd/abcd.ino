
int LS1 = 3;
int LS2 = 2 ;
int RS1 = A3;
int RS2 = A4 ;
int FS = 4;
int FLS = A5;
int MS = A2;
int RM1 = 8;
int RM2 = 9;
int ENR = 10;
int ENL = 11;
int LM1 = 12;
int LM2 = 13;
char a[200];
char b[150];
int i, j;


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

void setup()
{
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
  
}

void loop()
{
  IR1();
  }


void IR1()
{ 
  //000111
  if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
   
  }
  //000110
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
   
  }
  //001110
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //001111
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
    
  }
  //000000
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
    
  }
  //000001
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
 
  }
  //000010
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
    
  }
  //000011
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
   
  }
  //100001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BR();
      }  
  //100000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    fwd();
   
  }  
  //110000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    fwd();
   
  }
  //110001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BR();
    
  }
  //111110
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    fwd();
  }
  //111111
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BR();
  
  }
  //111000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    fwd();
   
  }
  //111001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1)
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BR();
    
  }
   //111101
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0 && digitalRead(FS) == 1)
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BR();
    
  }
  //10011
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //01111
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1  )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //11011
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    fwd();
  }
  //11110
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BR();
  }
  //11001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    BR();
  }
  //0000000
  if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0&& digitalRead(FLS)== 0 )
  {
    analogWrite(ENL,57);     // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,56);     // RIGHT MOTOR SPEED (0-254)
    stop();
    a[i] = 'T';
    i = i + 1;
    

  

  }

}
