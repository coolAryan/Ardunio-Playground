#include<LiquidCrystal.h>
LiquidCrystal lcd(3,4,5,6,7,13);
void setup() 
{
 lcd.begin(16,2);

}
void loop() 
{

       lcd.setCursor(0,0);
       lcd.print("Aryan");
   
    

  
}
