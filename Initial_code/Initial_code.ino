#include <TinyGPS.h>

TinyGPS gps;

long dist;
char inchar;
char inarray[] = "00000";

void setup() {
  // put your setup code here, to run once:
  Serial2.begin(9600); // Serial port for the GPS module
  Serial3.begin(115200); //Serial port for the laser
}



void loop() {
  // put your main code here, to run repeatedly: 

  if(Serial3.available())
  {
    inchar = Serial3.read();
    if(inchar == 'D')
    {     
      inarray[0] = inchar;
      for(int i = 1; i<5; i++)
      {
        inarray[i] = Serial3.read();
      }
      Serial.println(inarray);
      if (strcmp(inarray, "Dist:")  == 0)  // test to see if the two strings are equal
      {
        dist == Serial3.parseInt();
        Serial.print("Distance = ");
        Serial.println(dist);
      }
      memset(inarray, 0, sizeof(inarray)); // fill the array with zeros to clear it

      /*
      Serial3.readBytesUntil(',',inarray,30);
       Serial.print("D");
       Serial.println(inarray);
       */
    }
  }

}


