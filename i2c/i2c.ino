#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);
int c=0;
void setup()
{
  lcd.begin();
  lcd.backlight();
  
  // Initialize the serial port at a speed of 9600 baud
 
}
void loop()
{for(int i=0;i<16;i++)
{
  lcd.setCursor(0,i);
  lcd.print("b");
  delay(1000);
  lcd.clear();
 
}
}
