//int S0= A0;//output freq scaling
//int S1= A1;//output freq scaling
int S2= 6;
int S3= 7;
int sensorOut= 5;
int red,green,blue;
void setup() {
//  pinMode(S0,OUTPUT);
//  pinMode(S1,OUTPUT);
  //pinMode(A0,OUTPUT);
  //digitalWrite(A0,HIGH);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(sensorOut, INPUT);
//digitalWrite(S0,HIGH);
//digitalWrite(S1,HIGH);
  Serial.begin(9600);
}
void loop() 
{
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  red = pulseIn(sensorOut, LOW);
  //red= map(red,53,295,255, 0);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(red);//printing RED color frequency
  Serial.print("  ");
  delay(500);  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  green = pulseIn(sensorOut, LOW);
  //green= map(green,74,291, 255, 0);
  //Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(green);//printing RED color frequency
  Serial.print("  ");
  delay(500);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blue = pulseIn(sensorOut, LOW);
  //blue= map(blue,57,158, 255, 0);
  Serial.print("B= ");
  Serial.print(blue);
  Serial.println("  ");
  delay(500);
  Serial.print("\n"); 
   if( blue<green && red < green )
    {
      if(red>200)
      {
      Serial.println(" No Object");
      }
      else if(red<170)
      {
     Serial.println(" - RED detected!");
     digitalWrite(A0,LOW);
     digitalWrite(A1,LOW);//yellow
      }
    }
    else if(green <blue && red < green)
    {
      
    if(red<120 && green<120)
    {
      Serial.println(" - YELLOW detected!");
      digitalWrite(A1,LOW);
      digitalWrite(A0,HIGH);
    }
     
    } 
  else if(green <blue && red > green) 
  {
   Serial.println(" - GREEN detected!");
   digitalWrite(A0,LOW);
   digitalWrite(A1,HIGH);
  }
  
}


/*
digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // blue = map(blueFrequency, 38, 84, 255, 0);
  blue = map(blueFrequency, XX, XX, 255, 0);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blue);
  delay(100);

  // Checks the current detected color and prints
  // a message in the serial monitor
  if(redColor > green && redColor > blue){
      Serial.println(" - RED detected!");
  }
  if(green > redColor && green > blue){
    Serial.println(" - GREEN detected!");
  }
  if(blue > redColor && blue > green){
  Serial.println(" - BLUE detected!");

  */
