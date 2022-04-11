#include <Arduino.h>
#include "IHM.h"

IHM maLED;

void setup()
{
  maLED.initLedRgb();
}
 
void loop()
{
  maLED.allumer_rouge();
  maLED.attendre_1s();
  maLED.allumer_vert();
  maLED.attendre_1s();
  maLED.allumer_bleu();
  maLED.attendre_1s();
  //maLED.eteindre();
}
 
