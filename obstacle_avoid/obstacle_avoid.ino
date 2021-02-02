

#include<Servo.h>
Servo SM;

#define LA 7
#define LB 6
#define RA 5
#define RB 4
#define ENA 9
#define ENB 3

#define trigpin 0
#define echo 1

void setup() {
  // put your setup code here, to run once:
  pinMode(LA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RA, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echo, INPUT);

  analogWrite(ENA, 220);
  analogWrite(ENB, 240);

  SM.attach(9);
  SM.write(90);
  delay(3000);


}
int distance;
void loop() {
  // put your main code here, to run repeatedly:
  findDistance() ;

  if (distance > 35) {
    forward();
  } else {
    delay(60);
    findDistance();
    if (distance > 35) {
      forward();
    } else {
      Stop();
      SM.write(40);
      delay(500);
      findDistance();
      if (distance>35){
        SM.write(90);
        delay(1000);
        rightward();
        delay(500);
        Stop();
      }else{
        SM.write(130);
        delay(1000);
        findDistance();
        if (distance>35){
          SM.write(90);
          delay(1000);
          leftward();
          delay(500);
          Stop();
        }else{
          SM.write(90);
          delay(1000);
          rightward();
          delay(1500);
          Stop();
          
        }
      }
    }
  }
}
void forward() {
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
}
void backward() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RA, LOW);
  digitalWrite(RB, HIGH);
}
void leftward() {
  digitalWrite(LA, HIGH);
  digitalWrite(LB, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(RB, HIGH);
}
void rightward() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, HIGH);
  digitalWrite(RA, HIGH);
  digitalWrite(RB, LOW);
}
void Stop() {
  digitalWrite(LA, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(RA, LOW);
  digitalWrite(RB, LOW);
}

void findDistance() {
  int duration;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (1 / 29.1) * (duration / 2);
  delay(60);

}

