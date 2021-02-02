#include<EEPROM.h>
char name[]="ARYAN";
void setup() 
{
  Serial.begin(9600);
  for(int i=0;name[i]!='\0';i++)
  {EEPROM.write(i,name[i]);
    }
    for(int i=0;name[i]!='\0';i++)
    {
 Serial.println((char)(EEPROM.read(i)));
    }
}
void loop() 
{
 

}
