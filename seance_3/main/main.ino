#include <Arduino.h>
#include "IHM.h"

IHM monIHM;
//int mode = 1;

void setup()
{
  monIHM.init_IHM();
}
 
void loop()
{
//  monIHM.allumer_rouge();
//  monIHM.attendre_1s();
//  monIHM.allumer_vert();
//  monIHM.attendre_1s();
//  monIHM.allumer_bleu();
//  monIHM.attendre_1s();
//  monIHM.eteindre();

    monIHM.welcome_page();
    //monIHM.underline(mode);
    monIHM.allumer_orange();   
}
 
