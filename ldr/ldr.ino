int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int maxm=0;
int y;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
}

void loop() {
  y=analogRead(ldr1);
    Serial.print(y);
    Serial.print("\t");
   /* analogRead(ldr2);
    Serial.print(ldr2);
     Serial.print("\t");
    analogRead(ldr3);
    Serial.print(ldr3);
     Serial.print("\t");*/
    
   
     Serial.print("\n");
  
  }
  // put your main code here, to run repeatedly:
