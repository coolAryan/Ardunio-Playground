int j1=0;
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


int S2 = 6;
int S3 = 7;
int sensorOut = 5;
int red, green, blue;
int led1 = 0 ;
int led2 = 1;
int series[3];
char a[200];
char b[150];
int i, j, flag;

int k[200];

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
//  pinMode(S0, OUTPUT);
  //pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
 // pinMode(A5,OUTPUT);
 

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

    Serial.begin(9600);

}

void loop()
{

  IR1();

}
void blinked ()
{
  //pinMode(A5,OUTPUT);
  for ( i = 0; i <= 2; i++)
  {

    
    if (series[i] == 1)
    { digitalWrite(A0, HIGH);
    delay(2000);
    digitalWrite(A0, LOW);
    delay(1000);
    }
    else if (series[i] == 2)
    { digitalWrite(A1, HIGH);
    delay(2000);
    digitalWrite(A1, LOW);
    delay(1000);
    }
    else if (series[i] == 3)
    { digitalWrite(A5, HIGH);
    delay(2000);
    digitalWrite(A5, LOW);
    delay(1000);
    }


    
  }
}
int color(int j1)
{
 int color[3];
 int r=0,g=0,y=0,n=0;
 for(int i=0;i<30;i++)
 {
  //read red
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  red = pulseIn(sensorOut, LOW);
  Serial.print("R= ");
  Serial.print(red);
  Serial.print("  ");
  //read green
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  green=pulseIn(sensorOut,LOW);
  Serial.print("G= ");
  Serial.print(green);
  Serial.print("  ");
  //read blue
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blue=pulseIn(sensorOut,LOW);
  Serial.print("B= ");
  Serial.print(blue);
  Serial.print("  ");
  //print color
  Serial.print("\n");
  
   if( blue<green && red < green )
    {
      if(red>200)
      {
      Serial.println(" No Object");
      color[i]=0;
      }
      else if(red<170)
      {
     Serial.println(" - RED detected!");
     color[i]=1;
      }
    }
    else if(green <blue && red < green)
    {
      
    if(red<120 && green<120)
    {
      Serial.println(" - YELLOW detected!");
      color[i]=2;
    }
     
    } 
  else if(green <blue && red > green) 
  {
   Serial.println(" - GREEN detected!");
   color[i]=3;
  }
     delay(250);
  }
 

 
 //checking the occurance of colour  
 for(int i=0;i<30;i++)
  {
   if(color[i]==1)
   {  r++;  }
   else if(color[i]==2)
   {  y++;  }
   else if(color[i]==3)
   {  g++;  }
   else if(color[i]==0)
   {  n++;  } 
  }

  //comparing the occurance
  if((r > y)&&(r > g)&&(r > n))
  {
    //digitalWrite(red_l,HIGH);
    series[j1]=1;
    return j1++;
    }
  else if((y > r)&&(y > g)&&(y > n))
  {
   // digitalWrite(yellow_l,HIGH);
    series[j1]=2;
    return j1++;
    }   
  else if((g > y)&&(g > r)&&(g > n))
  {
   // digitalWrite(green_l,HIGH);
    series[j1]=3;
    return j1++;
    }
  else if((n > y)&&(n > g)&&(n > r))
  {
    //
    Serial.print("no object");
    return j1;
    }
//
//-------------------------------
  }
// 0 - MEANS WHITE
// 1 - MEANS BLACK

void IR1()
{
  //   delay(300);
  
  //000111
  if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54); 
    BL();
    
    
    }
  
    
  
  //000110
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);
    // RIGHT MOTOR SPEED (0-254)
    BL();
    
    
    
  }
  //001110
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  /*//00011
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 56);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 55);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }*/
  
  //001111
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BL();
   
  }
  //000000
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 54);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 53);     // RIGHT MOTOR SPEED (0-254)
    BL();
    
    
  }
  //000001
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 54);   
    analogWrite(ENR, 53);     // RIGHT MOTOR SPEED (0-254)
    BL();
    
   
     
  }
  //000010
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR,54);     // RIGHT MOTOR SPEED (0-254)
    BL();
    
  }
  //000011
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BL();
   //11001
   //10011
  }
  //100001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BR();
    
  }  
  //100000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    fwd();
    
    
  }  
  //110000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    fwd();
    
    
  }
  //110001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BR();
    
  }
  //111110
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    fwd();
  }
  //111111
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1 && digitalRead(FS) == 1 )
  {
    if(digitalRead(MS) == 1)
  {
     if(j1<3)
          {j1=color(j1);
          }
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54); 
    
          // RIGHT MOTOR SPEED (0-254)
    BR();
    
  }
  }
  //111000
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    fwd();
   
  }
  //111001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 1)
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BR();
    
  }
   
  //10011
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {
  //  while(digitalRead(LS2)!=1 && digitalRead(RS1)!=0)
  
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BL();
  
  }
  //01111
  else if(digitalRead(LS1) == 0 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1  )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BL();
  }
  //11011
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 1 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    fwd();
    
  }
  //11110
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 1 && digitalRead(RS1) == 1 && digitalRead(RS2) == 0)
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BR();
  }
  //11001
  else if(digitalRead(LS1) == 1 && digitalRead(LS2) == 1 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 1)
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    BR();
  }
  //0000000
  if(digitalRead(LS1) == 0 && digitalRead(LS2) == 0 && digitalRead(MS) == 0 && digitalRead(RS1) == 0 && digitalRead(RS2) == 0 && digitalRead(FS) == 0&& digitalRead(FLS)== 0 )
  {
    analogWrite(ENL, 55);    // LEFT MOTOR SPEED (0-254)
    analogWrite(ENR, 54);     // RIGHT MOTOR SPEED (0-254)
    stop();
    delay(1000);
       digitalWrite(3,LOW);
       digitalWrite(2,LOW);
       digitalWrite(A3,LOW);
       digitalWrite(A4,LOW);
       digitalWrite(4,LOW);
       digitalWrite(A5,LOW);
       digitalWrite(A2,LOW);
      blinked();
  }
}
