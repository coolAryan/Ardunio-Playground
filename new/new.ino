char a[200];
char k[200];
char h[150];
int i,j;
int S0= A0;
int S1= A1;
int S2= 6;
int S3= 7;
int sensorOut= 5;
int red,green,blue;
int path_length = 0;
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


int count = 0;


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
 for (int i = 0; a[i] != '\0'; i++)
  {
   a[i]=Serial.read();
   Serial.print("\n");
  }
  Serial.print("\n");
  
  
  for (int i = 0; a[i] != '\0'; i++)
  {
    k[i] = a[i];
    path_length = i;
  }
    for (int i = 0; a[i] != '\0'; i++)
  {
   if(k[i]=='B')
   {
    color();
     if(red < green)
     {
     if(red < blue && blue<green)
     {
     Serial.println(" - RED detected!");
  
     h[i]='R';
     i++;
     }
    if(green <blue)
    {
      Serial.println(" - YELLOW detected!");
      
      h[i]='Y';
      i++;
    }  
  }
  else if(green < red && green <blue)
  {
    Serial.println(" - GREEN detected!");
   
    h[i]='G';
    i++;
  }
  else if(blue < red && blue < green)
  {
  Serial.println(" - BLUE detected!");
  
  h[i]='B';
  i++;
  }

   
 }
 if(k[i]=='S')
 {
  
  for (int i = 0; h[i] != '\0'; i++)
  {
   Serial.print(h[i]);
   Serial.print("\n");
  }
  }
    
 }
  }

  /*for (int i = 0; i <= path_length; i++ )
  {
    Serial.print(b[i]);

  }*/
