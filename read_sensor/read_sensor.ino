int LS1 =3;
int LS2 =2 ;
int RS1 = A1;
int RS2 =A0 ;
int FS = 4;
int MS = A2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LS1, INPUT);
  pinMode(LS2, INPUT);
  pinMode(RS1, INPUT);
  pinMode(RS2, INPUT);
  pinMode(FS, INPUT);
//  pinMode(FLS, INPUT);
  pinMode(MS, INPUT);
  //pinMode(5, INPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.print(digitalRead(LS2));
  Serial.print("\t");
  Serial.print(digitalRead(LS1));
  Serial.print("\t");
  Serial.print(digitalRead(MS));
  Serial.print("\t");
  Serial.print(digitalRead(RS1));
  Serial.print("\t");
  Serial.print(digitalRead(RS2));
  Serial.print("\t");
  Serial.print(digitalRead(FS));
  Serial.print("\t");
//  Serial.print(digitalRead(FLS));
  
  
 
 
 Serial.print("\n");
  // put your main code here, to run repeatedly:

}
