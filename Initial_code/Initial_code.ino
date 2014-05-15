#include <TinyGPS.h>

TinyGPS gps;

long dist;
char inchar;
String inarray = "                                                            ";
int stt = 0;
int edd = 0;

void measure()
{
  Serial.println("Taking Measurement");
  while(Serial3.available()) Serial3.read(); // Wipe the incoming buffer

  Serial3.print("*11114#"); // Send the actual command to measure the distance
  delay(20);
  stt = 0;

  for(int i = 0; i<inarray.length(); i++)
  {
    while(!Serial3.available())
    {
      ;
    }
    inarray[i] = Serial3.read();
  }

  if (inarray.substring(0,10) == "*00026062#") 
  {
    //Serial.println("Valid");
  }
  edd = inarray.lastIndexOf('#');
  inarray.setCharAt(edd + 1,'\0');
  inarray.setCharAt(edd - 1,'#');
  inarray.setCharAt(edd - 2,'#');
  inarray.trim();
  //Serial.println(inarray);
  stt = inarray.indexOf('*',10);
  //Serial.print("len:");
  //Serial.println(inarray.length());
  //Serial.print("stt:");
  //Serial.println(stt);

  if(stt > 0)
  {
  // Serial.print("d1:");
    String d1 = String(inarray.substring(stt+6));
  //  Serial.println(d1);
    int d2 = d1.toInt();
  //  Serial.print("d2:");
  //  Serial.println(d2);
  }

  for(int i=0; i<inarray.length(); i++)
  {
    inarray[i] = ' ';
  }
}

void reposition()
{
  Serial.print(); // print horizontal angle
  Serial.print(); // print vertical angle
  Serial.print(d2); // print the distance
  
}

void setup() {
  // put your setup code here, to run once:
  Serial2.begin(9600); // Serial port for the GPS module
  Serial3.begin(115200); //Serial port for the laser
}

void loop() {
  // put your main code here, to run repeatedly: 

  delay(5000);
  measure();
  if(stt > 0) reposition();
}






