
static char path[100],cpy_path[100],short_path[50];

int ML1 = 3;
int ML2 = 5;
int MR1 = 6;
int MR2 = 9;
int enR = 3;
int enL = 9;

int SensorL2 =  4 ;
int SensorL1 = 7 ;
int SensorM  = 8 ;
int SensorR1 = 12 ;
int SensorR2 = 13 ;


int i=0;


//Speed of the Motors

void setup() {

 
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(SensorL2, INPUT);
  pinMode(SensorL1, INPUT);
  pinMode(SensorM, INPUT);
  pinMode(SensorR1, INPUT);
  pinMode(SensorR2, INPUT);
}
 
  
void RIGHT(){
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, LOW );
  }
  void LEFT(){
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, LOW);
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);
  }
  void FR(){
    //FORWARD
    digitalWrite(ML1, HIGH);
    digitalWrite(ML2, LOW);
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);
    
}
 void UT(){
    
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, HIGH);
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);
    
}
 void STOP(){
   
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, LOW);
    digitalWrite(MR1, LOW);
    digitalWrite(MR2, LOW);
    
}

void loop() {
  
  Serial.begin(9600);
  analogWrite(enR, 200);
  analogWrite(enL, 200);
  SensorL2 = digitalRead(4);
  SensorL1 = digitalRead(7);
  SensorM  = digitalRead(8);
  SensorR1 = digitalRead(12);
  SensorR2 = digitalRead(13);
  //FORWARD
 if (SensorL2 == 0 && SensorL1 == 0 && SensorM == 1 && SensorR1 == 0 && SensorR2 == 0 )
 {
   FR();
 }
 //RIGHT
 if(SensorL2 == 0 && SensorL1 == 0 && SensorM == 0 && SensorR1 == 1 && SensorR2 == 1 )
 {
   RIGHT();
    path[i]='R';
    i++;
 }
 //LEFT
 if(SensorL2 == 1 && SensorL1 == 1 && SensorM == 0 && SensorR1 == 0 && SensorR2 == 0 )
 {
   LEFT();
     path[i]='L';
    i++;
 }
 // -| 
  if(SensorL2 == 1 && SensorL1 == 1 && SensorM == 1 && SensorR1 == 0 && SensorR2 == 0 )
 {
   LEFT();
   path[i]='L';
      i++;
 }
 // |-
  if(SensorL2 == 0 && SensorL1 == 0 && SensorM == 1 && SensorR1 == 1 && SensorR2 == 1 )
 {
   FR();
     path[i]='S';
      i++;
 }
 //U TURN
 if(SensorL2 == 0 && SensorL1 == 0  && SensorM == 0 && SensorR1 == 0 && SensorR2 == 0 )
 {
   UT();
    path[i]='U';
    i++;
 }
 //T POINT
if(SensorL2 == 1 && SensorL1 == 1 && SensorM == 0 && SensorR1 == 1 && SensorR2 == 1 ) 
{
  LEFT();
  path[i]='L';
    i++;
}
//4 WAy
if(SensorL2 == 1 && SensorL1 == 1 && SensorM == 1 && SensorR1 == 1 && SensorR2 == 1 )
{
  LEFT();
  path[i]='L';
    i++;
}

while (i==25)
  {
    for(int j=0;j<i;j++)
      Serial.println(path[j]);
  }
  if (i==30)
    void shortpath();
}
void shortpath()
{
  for (int k=0;k<i;k++)
    cpy_path[k] = path[k];
  int x,y=0;
  for( x=1;x<i;x++)
  {
    if(cpy_path[x-1]=='L'&&cpy_path[x]=='U'&&cpy_path[x+1]=='L')    //LUL
      {
        short_path[y]='S';
        y++;
      }
    
    if(cpy_path[x-1]=='R'&&cpy_path[x]=='U'&&cpy_path[x+1]=='R')    //RUR
      {
        short_path[y]='S';
        y++;
      }
    
    if(cpy_path[x-1]=='R'&&cpy_path[x]=='U'&&cpy_path[x+1]=='L')    //RUL
      {
        short_path[y]='U';
        y++;
      }
    
    if(cpy_path[x-1]=='L'&&cpy_path[x]=='U'&&cpy_path[x+1]=='R')    //LUR
      {
        short_path[y]='U';
        y++;
      }
    
    if(cpy_path[x-1]=='L'&&cpy_path[x]=='U'&&cpy_path[x+1]=='S')    //LUS
      {
        short_path[y]='R';
        y++;
      }
    
    if(cpy_path[x-1]=='S'&&cpy_path[x]=='U'&&cpy_path[x+1]=='L')    //SUL
      {
        short_path[y]='R';
        y++;
      }

    if(cpy_path[x-1]=='R'&&cpy_path[x]=='U'&&cpy_path[x+1]=='S')    //RUS
      {
        short_path[y]='L';
        y++;
      }
    
    if(cpy_path[x-1]=='S'&&cpy_path[x]=='U'&&cpy_path[x+1]=='R')    //SUR
      {
        short_path[y]='L';
        y++;
      }
    }
    for (int k=0; k<y;k++)
      Serial.print(short_path[k]+"\t");
}

