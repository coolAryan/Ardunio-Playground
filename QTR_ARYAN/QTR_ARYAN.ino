
#include <QTRSensors.h>  
#define NUM_SENSORS   8 
#define TIMEOUT       2500  
#define EMITTER_PIN   QTR_NO_EMITTER_PIN  

QTRSensorsRC qtrrc((unsigned char[]) {2, 4, 5, 6, 7, 8, 9, 10},NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];
unsigned int line_position=0; // value from 0-7000 to indicate position of line between sensor 0 - 7

int ENL=3;  //PWM control for motor outputs 1 and 2 is on digital pin 10  (Left motor)
int ENR=11;  //PWM control for motor outputs 3 and 4 is on digital pin 11  (Right motor)
int L1=15;  
int L2=14;
int R1= 12 ; 
int R2=13 ;
int calSpeed = 40; 
int maxspeed=100;
int basespeed=100;
float Kp;
float Kd;
float error,last_error;



// tune value motors will run while auto calibration sweeping turn (0-255)
 // tune value in mseconds motors will run past intersection to align wheels for turn


void setup()
{
 
  Serial.begin(9600);   
  delay(2000);
  for (int i = 0; i <= 400; i++)  // begin calibration cycle to last about 2.5 seconds (100*25ms/call)
  {
    
    // auto calibration sweeping left/right, tune 'calSpeed' motor speed at declaration 
   
       digitalWrite(L1, HIGH); 
       digitalWrite(L2, LOW);
       analogWrite(ENL, calSpeed);
       digitalWrite(R2, HIGH);  
       digitalWrite(R1, LOW);
       analogWrite(ENR, calSpeed);   
    qtrrc.calibrate();       // reads all sensors with the define set 2500 microseconds (25 milliseconds) for sensor outputs to go low.
  }  
  line_position = qtrrc.readLine(sensorValues);
  
 
        digitalWrite(ENL, 0);  // stop right motor first which kinda helps avoid over run
  digitalWrite(ENR, 0);  
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  Serial.println("Calibration Complete");
  delay(1000);
  
}
void MazeSolve()
{
  // Loop until we have solved the maze.
  while(1)
  {
    // FIRST MAIN LOOP BODY  
    follow_line();

    // Drive straight a bit.  This helps us in case we entered the
    // intersection at an angle.
    digitalWrite(L1, HIGH); 
       digitalWrite(L2, LOW);
       analogWrite(ENL,200);
       digitalWrite(R1, HIGH);  
       digitalWrite(R2, LOW);
       analogWrite(ENR,200);  

    // These variables record whether the robot has seen a line to the
    // left, straight ahead, and right, whil examining the current
    // intersection.
    unsigned char found_left=0;
    unsigned char found_straight=0;
    unsigned char found_right=0;
    
    // Now read the sensors and check the intersection type.
    line_position = qtrrc.readLine(sensorValues);

    // Check for left and right exits.
    if(sensorValues[0] > 200)
    found_right = 1;
    if(sensorValues[7] > 200)
    found_left = 1;

    // Drive straight a bit more - this is enough to line up our
    // wheels with the intersection.
    digitalWrite(L1, HIGH); 
       digitalWrite(L2, LOW);
       analogWrite(ENL,200);
       digitalWrite(R1, HIGH);  
       digitalWrite(R2, LOW);
       analogWrite(ENR,200);  
    delay(300); 
  
    line_position = qtrrc.readLine(sensorValues);
    if(sensorValues[1] > 200 || sensorValues[2] > 200 || sensorValues[3] > 200 || sensorValues[4] > 200 || sensorValues[5] > 200 || sensorValues[6] > 200)
    found_straight = 1;

    // Check for the ending spot.
    // If all six middle sensors are on dark black, we have
    // solved the maze.
    if(sensorValues[1] > 600 && sensorValues[2] > 600 && sensorValues[3] > 600 && sensorValues[4] > 600 && sensorValues[5] > 600 && sensorValues[6] > 600)
  break;

    // Intersection identification is complete.
    // If the maze has been solved, we can follow the existing
    // path.  Otherwise, we need to learn the solution.
    unsigned char dir = select_turn(found_left, found_straight, found_right);

    // Make the turn indicated by the path.
    turn(dir);

    // Store the intersection in the path variable.
    path[path_length] = dir;
    path_length ++;
  }
   while(1)
  {
    //  maybe you would like to add a blinking led or a beeper.
    //  we just have it waiting patiently to be placed back on the starting line.
    analogWrite(ENL, 0);  // stop both motors
    analogWrite(ENR, 0);
  
    // while(1){}; // uncomment this line to cause infinite loop to test if end was found if your robot never seems to stop

    // hold motors while robot is sitting on end point
    line_position = qtrrc.readLine(sensorValues);
    while(sensorValues[1] > 200 && sensorValues[2] > 200 && sensorValues[3] > 200 && sensorValues[4] > 200 && sensorValues[5] > 200 && sensorValues[6] > 200)
    {
      line_position = qtrrc.readLine(sensorValues);
      delay(50);
    }
}
}
void loop()
{
  // read calibrated sensor values and obtain a measure of the line position from 0 to 7000
  // To get raw sensor values, call:
  //  qtrrc.read(sensorValues); instead of unsigned int position = qtrrc.readLine(sensorValues);
  unsigned int line_position = qtrrc.readLine(sensorValues);
  
  //Serial.println(); // uncomment this line if you are using raw values
  Serial.print(line_position); // comment this line out if you are using raw values
  Serial.print("  ");
  Serial.print(sensorValues[0]);
  Serial.print("  ");
  Serial.print(sensorValues[1]);
  Serial.print("  ");
  Serial.print(sensorValues[2]);
  Serial.print("  ");
  Serial.print(sensorValues[3]);
   Serial.print("  ");
  Serial.print(sensorValues[4]);
  Serial.print("  ");
  Serial.print(sensorValues[5]);
     Serial.print("  ");
  Serial.print(sensorValues[6]);
   Serial.print("  ");
  Serial.print(sensorValues[7]);
  Serial.print("\n");
  
 // begin maze solving
  MazeSolve(); // comment out and run serial monitor to test sensors while manually sweeping across line

}  // end main loop



//line following subroutine
// PD Control
void follow_line()  //follow the line
{

  lastError=0;
  
  while(1)
  {
    line_position = qtrrc.readLine(sensorValues);
    
        error = (float)line_position - 3500;
   
        // set the motor speed based on proportional and derivative PID terms
        // kp is the a floating-point proportional constant (maybe start with a value around 0.5)
        // kd is the floating-point derivative constant (maybe start with a value around 1)
        // note that when doing PID, it's very important you get your signs right, or else the
        // control loop will be unstable
        Kp=.5;
        Kd=1;
         int motorspeed=Kp*error+ Kd*(error - lastError);
        lastError = error;
        //this codes limits the PV (motor speed pwm value)  
        // limit PV to 55
        int rightmotorSpeed = 200 + motorspeed;
        int leftmotorSpeed = 200 -motorspeed;
        //set motor speeds
        set(rightspeed,leftspeed);
        break;
    }
  
    // We use the inner six sensors (1 thru 6) to
    // determine if there is a line straight ahead, and the
    // sensors 0 and 7 if the path turns.
    if(sensorValues[1] < 100 && sensorValues[2] < 100 && sensorValues[3] < 100 && sensorValues[4] < 100 && sensorValues[5] < 100 && sensorValues[6] < 100)
    {
      // There is no line visible ahead, and we didn't see any
      // intersection.  Must be a dead end.
      return;
    }

    else if(sensorValues[0] > 200 || sensorValues[7] > 200)
    {
      // Found an intersection.
      return;
    }

  } 

 // end follow_line  
void set(int leftspeed,int rightspeed)
{
  if(rightmotorspeed>maxspeed)
  {rightmotorspeed=maxspeed;
  }
  if(leftmotorspeed>maxspeed)
  {leftmotorspeed=maxspeed;
  }  
  if(rightmotorspeed<0)
  {rightmotorspeed=0;
  }  
  if(leftmotorspeed<0)
  {leftmotorspeed=0;
  }  
        digitalWrite(L1, HIGH); 
       digitalWrite(L2, LOW);
       analogWrite(ENL,leftmotorspeed);
       digitalWrite(R2, HIGH);  
       digitalWrite(R1, LOW);
       analogWrite(ENR,rightmotorspeed);  
}

     
// Turns to the sent variable of
// 'L' (left), 'R' (right), 'S' (straight), or 'B' (back)
// Tune 'turnSpeed' at declaration
void turn(char dir)
{
  switch(dir)
  {
    // Turn left 90deg
    case 'L':    
      digitalWrite(dir_a, HIGH); 
      analogWrite(pwm_a, turnSpeed);
      digitalWrite(dir_b, LOW);  
      analogWrite(pwm_b, turnSpeed);
      
      line_position = qtrrc.readLine(sensorValues);
      
      while (sensorValues[6] <200)  // wait for outer most sensor to find the line
      {
        line_position = qtrrc.readLine(sensorValues);
      }
  
      // slow down speed
      analogWrite(pwm_a, turnSpeedSlow);
      analogWrite(pwm_b, turnSpeedSlow); 
      
      // find center
      while (line_position > 4350)  // tune - wait for line position to find near center
      {
        line_position = qtrrc.readLine(sensorValues);
      }
     
      // stop both motors
      analogWrite(pwm_b, 0);  // stop right motor first to better avoid over run
      analogWrite(pwm_a, 0);  
      break;
      
    // Turn right 90deg
    case 'R':        
      digitalWrite(dir_a, LOW); 
      analogWrite(pwm_a, turnSpeed);
      digitalWrite(dir_b, HIGH);  
      analogWrite(pwm_b, turnSpeed);
           
      line_position = qtrrc.readLine(sensorValues);
      
      while (sensorValues[1] <200)  // wait for outer most sensor to find the line
      {
        line_position = qtrrc.readLine(sensorValues);
      }
    
      // slow down speed
      analogWrite(pwm_a, turnSpeedSlow);
      analogWrite(pwm_b, turnSpeedSlow); 
      
      // find center
      while (line_position < 3250)  // tune - wait for line position to find near center
      {
        line_position = qtrrc.readLine(sensorValues);
      }
     
      // stop both motors
      analogWrite(pwm_a, 0);  
      analogWrite(pwm_b, 0);      
      break;
    
    // Turn right 180deg to go back
    case 'B':    
      digitalWrite(dir_a, LOW); 
      analogWrite(pwm_a, turnSpeed);
      digitalWrite(dir_b, HIGH);  
      analogWrite(pwm_b, turnSpeed);
      
      line_position = qtrrc.readLine(sensorValues);
  
      while (sensorValues[1] <200)  // wait for outer most sensor to find the line
      {
        line_position = qtrrc.readLine(sensorValues);
      }
       
      // slow down speed
      analogWrite(pwm_a, turnSpeedSlow);
      analogWrite(pwm_b, turnSpeedSlow); 
      
      // find center
      while (line_position < 3250)  // tune - wait for line position to find near center
      {
        line_position = qtrrc.readLine(sensorValues);
      }
     
      // stop both motors
      analogWrite(pwm_a, 0);  
      analogWrite(pwm_b, 0);           
      break;

    // Straight ahead
    case 'S':
      // do nothing
      break;
  }
} 
*/


  // Solved the maze!

  // Now enter an infinite loop - we can re-run the maze as many
  // times as we want to.
 
 
  
} // end MazeSolve
