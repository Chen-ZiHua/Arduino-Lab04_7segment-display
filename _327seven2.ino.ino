
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
  int Hour=0,Min=0;
  int step=1;
  int Pin10;
  //int Pin11;
  
void setup()
{
  pinMode(A4,INPUT_PULLUP);
  //pinMode(A5,INPUT_PULLUP);
  
  byte numDigits = 4;
  byte digitPins[] = {5, 4, 3, 2};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, numDigits,digitPins,segmentPins);
}

void loop() 
{
      Pin10 = digitalRead(A4);
  // Pin11 = digitalRead(A5);
    if (Pin10==0)
      Min = Hour = 0;
  /* if(Pin11==0)
      step=-1;
  else
    step=1;*/
    sevseg.setNumber(Hour * 100 + Min, 4);
  Min = Min + step;
  if( Min == 60)
  {
      Min=0;
      Hour=Hour+1;
     if(Hour==24)
     {
          Min=0;
          Hour=0;
     }
  
  } // overflow
    if( Min == -1 )
  {
        Min = 59; 
        Hour=Hour-1;
      if (Hour == -1) 
      {
          Hour = 23;
      } 
 
  }
   for(int i=0;i<8000;i++)
      {
          sevseg.refreshDisplay();
           sevseg.refreshDisplay();
      }
}

