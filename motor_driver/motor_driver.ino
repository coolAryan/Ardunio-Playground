
int RM1 = 12;
int RM2 = 13;
int ENR = 10;
int ENL = 11;
int LM1 = 8;
int LM2 = 9;
int led=7;

void BR()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM2, HIGH);
}

void setup() {
  // put your setup code here, to run once:
    pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENL, OUTPUT);
  pinMode(ENR, OUTPUT);
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ENL,70);
  analogWrite(ENR, 70);
  BR();
  delay(500);
}
