
int pwm_a = 3;  //PWM control for motor outputs 1 and 2 is on digital pin 10  (Left motor)
int pwm_b = 11;  //PWM control for motor outputs 3 and 4 is on digital pin 11  (Right motor)
int a1 = 12;  
int a2= 10;
int b1 = 7; 
int b2=  9;



  void setup()
{
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
}

void loop() 
{
       digitalWrite(a1, HIGH); 
       digitalWrite(a2, LOW);
       analogWrite(pwm_a,50);
       digitalWrite(b2, LOW);  
       digitalWrite(b1, HIGH);
       analogWrite(pwm_b,50);   
}
