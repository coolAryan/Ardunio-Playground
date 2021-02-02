#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
SoftwareSerial rfid (2, 3);
String tag;
int MS1 = 10;
int MS2 = 12;
int EN = 11;
void setup()
{
  pinMode(EN, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  rfid.begin(9600);
  Serial.print("Waiting For Input");
  lcd.print("Enter Input");
}
void motor()
{
  digitalWrite(EN, HIGH);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, LOW);
  delay(700);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  delay(100);
}
void reverse()
{
  digitalWrite(EN, HIGH);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, HIGH);
  delay(700);
}


void loop()
{
  if (rfid.available())
  {
    tag = rfid.readString();
    Serial.println(tag);
    lcd.setCursor(0, 1);
    //lcd.print(tag);
    delay(10);
    //Serial.clear();
    if (tag == "430077970DAE")
    { lcd.clear();
      Serial.print("Access Granted");
      lcd.print("Access Granted");
      delay(100);
      lcd.clear();
      lcd.print("Welcome to");
      lcd.setCursor(0, 1);
      lcd.print("Xananoids");
      delay(100);
      Serial.print("\n");
      Serial.print("NAME-Aryan");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("NAME-Aryan");
      lcd.setCursor(0, 1);
      Serial.print("\n");
      Serial.print("Id:422");
      Serial.print("\n");
      lcd.print("Id:422");
      delay(10);
      motor();
      tag = 1;

      // lcd.clear();
    }
    else if (tag == "18008920AC1D")
    { lcd.clear();
      Serial.print("Access Granted");
      lcd.print("Access Granted");
      delay(1000);
      lcd.clear();
      lcd.print("Welcome to");
      lcd.setCursor(0, 1);
      lcd.print("Xananoids");
      delay(1000);
      Serial.print("\n");
      Serial.print("NAME-Akshat");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("NAME-Akshat");
      Serial.print("\n");
      lcd.setCursor(0, 1);
      lcd.print("Id:406");
      Serial.print("Id:406");
      Serial.print("\n");
      motor();
      tag = 1;
    }
    else
    {
      lcd.clear();
      lcd.print("Access Denied");
    }
    //}
  }
}
