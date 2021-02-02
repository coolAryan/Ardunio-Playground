char a[200] = {'L', 'B', 'L','B','L','L'};
char k[200];
char b[150];
int i,j;
short not_the_shortest = 0;
int path_length = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


int count = 0;
void short_path_algorithm()
{
  delay(200);
  
   if (not_the_shortest == 1)
  {
    count = 0;
    j = 0;
    while(j <= path_length)
    {
      
      if (k[j] == 'L' && k[j + 1] == 'B' && k[j + 2] == 'L') //LBL
      {
        b[count] = 'S';
        count++;
        j=j+3;
      }
      else if (k[j] == 'R' && k[j + 1] == 'B' && k[j + 2] == 'L') //RBL
      {
        b[count] = 'B';
        count++;
        j=j+3;
      }
      else if (k[j] == 'L' && k[j + 1] == 'B' && k[j + 2] == 'R') //LBR
      {
        b[count] = 'B';
        count++;
        j=j+3;
      }
      else if (k[j] == 'L' && k[j + 1] == 'B' && k[j + 2] == 'S') //LBS
      {
        b[count] = 'R';
        count++;
        j=j+3;
      }
      else if (k[j] == 'S' && k[j + 1] == 'B' && k[j + 2] == 'L') //SBL
      {
        b[count] = 'R';
        count++;
        j=j+3;
      }
      else if ( k[j] == 'S' && k[j + 1] == 'B' && k[j + 2] == 'S')//SBS
      {
        b[count] = 'B';
        count++;
        j=j+3;
      }
      else
      {
        b[count] = k[j];
        count++;
        j++;
      }
      
    }
      for (int i = 0; k[i] != '\0'; i++)
    {
      k[i] = '\0'; 
    }
    
    for (i = 0; b[i] != '\0'; i++)
    {
      k[i] = b[i];
      Serial.print(k[i]);
      path_length=i;
    }
    Serial.println();
    not_the_shortest=0;
   
    short_path_algorithm();
    
  }

  else
  {
    //not_the_shortest=0;
    for (i = 0;i<path_length; i++)
    {
      if (k[i] == 'B')
      {
        not_the_shortest = 1;
      }
    }
    if (not_the_shortest == 1)
    {
       for(int i=0; b[i] != '\0'; i++)
      {
        b[i] = '\0';
        
      }
      short_path_algorithm();
    }

  Serial.print("Shortpath Found");

  Serial.print("Short Path is: ");         
    for(i=0;i<path_length;i++)
    {
      Serial.print(b[i]);
      delay(200);
    }
  }


  delay(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; a[i] != '\0'; i++)
  {
    k[i] = a[i];
    path_length = i;
  }
  
  Serial.println(path_length);
  Serial.println("The actual path is");
  /*for (int i = 0; i <= path_length; i++ )
  {
    Serial.print(b[i]);

  }*/
  Serial.println();
  delay(2000);
  short_path_algorithm();




}
