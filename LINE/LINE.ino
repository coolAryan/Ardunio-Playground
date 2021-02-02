int LS1=13;
int LS2=12;
int RS1=9;
int RS2=10;
int FS=11;

void setup() {
 Serial.begin(9600);
  pinMode(LS1,INPUT);
  pinMode(LS2,INPUT);
  pinMode(RS1,INPUT);
  pinMode(RS2,INPUT);
   pinMode(FS,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  
 int y=digitalRead(LS1);
 /*int z=digitalRead(LS2);
 int x=digitalRead(RS1);
 int q=digitalRead(RS2);
 int w=digitalRead(FS);
 
 Serial.print("\t");
 Serial.print(z);
 Serial.print("\t");
 Serial.print(x);
 Serial.print("\t");
 Serial.print(q);
Serial.print("\t");
 Serial.print(w);
 */
 Serial.print(y);
 Serial.print("\n");
 delay(100);
 
  
  // put your main code here, to run repeatedly:

}
