#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
  int Hour=0,Min=0;
  int step=1;
void setup()
{
  //Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins[] = {5, 4, 3, 2};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, numDigits,digitPins,segmentPins);
}

void loop() 
{
    sevseg.setNumber(Hour*100+Min,4);
    for(int i=0;i<10000;i++)
    {
      sevseg.refreshDisplay();
    }
    Min=Min+1;
    if(Min==60)
    {
      Min=0;
      if(Hour==23)
      Hour=0;
      else
      Hour++;
    }
}

