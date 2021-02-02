
int but_light = 12;
int led=13;
int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
       
int maxm=0;
void setup() {
    pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
   pinMode(but_light, INPUT);
   pinMode(led,OUTPUT);
   Serial.begin(9600);
}
void light()
  {
     analogRead(ldr1);
    Serial.print(ldr1);
    Serial.print("\t");
    analogRead(ldr2);
    Serial.print(ldr2);
     Serial.print("\t");
    analogRead(ldr3);
    Serial.print(ldr3);
     Serial.print("\t");
    if (ldr1 > maxm)
    {
      maxm = ldr1;
      //forward();
    }
    if (ldr2 > maxm)
    {
      maxm = ldr2;
      //right();
    }
    if (ldr3 > maxm)

    {
      maxm = ldr3;
      //left();
    }
    Serial.print(maxm);
     Serial.print("\n");
}

void loop() 
{
  
  if(digitalRead(but_light)==LOW)
  {
   
    digitalWrite(led,LOW);
  }
  else{
    digitalWrite(led,HIGH);
    }
  
}  
