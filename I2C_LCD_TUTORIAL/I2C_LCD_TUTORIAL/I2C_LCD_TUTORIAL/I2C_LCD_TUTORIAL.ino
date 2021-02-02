/* www.electronicsprojectshub.com */
/*Import following Libraries*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 16, 2);
int i=0;
int j=0;
void setup() 
{
Serial.begin(9600);
lcd.begin();//Defining 16 columns and 2 rows of lcd display
lcd.backlight();//To Power ON the back light
//lcd.backlight();// To Power OFF the back light

}

void loop() 
{
  for(i=0;i<17;i++)
  {
lcd.setCursor(i,0);
 //Defining positon to write from first row,first column .
lcd.print("A");
delay(100);
lcd.clear(); 
  }
  //You can write 16 Characters per line 


}
