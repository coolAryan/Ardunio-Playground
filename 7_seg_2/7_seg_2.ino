
    int a[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67};
    
void setup() 
{
  for (int l = 2; l < 10; l++)
  {
    pinMode(l, 1);
  }


}

void loop() 
{
 int rem=0;
  
 for(int k=0;k<8;k++)   
  {
    digitalWrite(k+2,a[rem]);
    delay(200);
    for(int j=0;j<8;j++)
    {
     digitalWrite(k+2,a[j]);
     delay(200);  
    }
    rem++;
  }
}
