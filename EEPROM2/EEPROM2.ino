#include<EEPROM.h>
int value[10];
int set[10];
int maxm=0;
void setup() 
{
  pinMode(13,OUTPUT);
  pinMode(A4,OUTPUT);
  Serial.begin(9600);
   analogRead(A4);
 for(int i=0;i<10;i++)
 {
  EEPROM.write(i,value[i]);
 }  
   for(int i=0;i<10;i++)
    {
     maxm=(value[i]+maxm)/10;
    }   
}
void loop() 
{
     for(int i=0;i<10;i++)
    {
      EEPROM.write(i,set[i]);
    }
    for(int i=0;i<10;i++)
    { 
        if(set[i]>maxm)
        {
          digitalWrite(13,1);  
        }
        else{digitalWrite(13,0); }
        
       }
    }
    
