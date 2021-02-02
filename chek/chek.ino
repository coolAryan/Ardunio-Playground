char k[10];
char a[10];
char h[10];
char t[10];
char i;
int j=0;
int z;
int f=0;
char m='\n';
int flag=0;
int S0= A0;
int S1= A1;
int S2= 6;
int S3= 7;
int sensorOut= 5;
int red,green,blue;
void setup() {
   pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void color()
  {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  red = pulseIn(sensorOut, LOW);
  // red= map(red,53,295,255, 0);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(red);//printing RED color frequency
  Serial.print("  ");
  delay(1000);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  green = pulseIn(sensorOut, LOW);
  //green= map(green,74,291, 255, 0);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(green);//printing RED color frequency
  Serial.print("  ");
  delay(1000);

  
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
 
  blue = pulseIn(sensorOut, LOW);
  //blue= map(blue,57,158, 255, 0);
  Serial.print("B= ");
  Serial.print(blue);
  Serial.print("  ");
  
  Serial.print("\n");
  
  delay(1000);
}
void neww()
{
  if(flag==1)
  {
    //Serial.print(a);
     for( z=0;k[z]!='\0';z++)
    if(k[z]=='B')
    {
      color();
       if(red < green)
     {
     if(red < blue && blue<green)
     {
     Serial.println(" - RED detected!");
  
     h[f]='R';
     f++;
     }
    if(green <blue)
    {
      Serial.println(" - YELLOW detected!");
      
      h[f]='Y';
      f++;
    }  
  }
  else if(green < red && green <blue)
  {
    Serial.println(" - GREEN detected!");
   
    h[f]='G';
    f++;
  }
  else if(blue < red && blue < green)
  {
  Serial.println(" - BLUE detected!");
  
  h[f]='B';
  f++;
  }
      }
   
      
      else if(k[z]=='S')
      {
        Serial.print("finished");
        for (int q = 0; h[q] != '\0'; q++)
  {
    t[q]=h[q];
   Serial.print(t[q]);
   Serial.print("\n");
  }
        
        }
    flag=0;
    }
    
    
  
  
  
  }
void loop() {
  recive();     

  neww();
}


void recive()
{
 
  
    while(Serial.available()>0 && flag==0 )
    {
      i=Serial.read();
      if(i!=m)
      {
        
        a[j]=i;
        k[j]=a[j];
        j++;
       if(j>=10)
       {
        j=9;
        }
          
          
      }
          else{
            
            a[j]='\0';
            j=0;
            flag=1;
            }
        
        }// put your main code here, to run repeatedly:
     }
