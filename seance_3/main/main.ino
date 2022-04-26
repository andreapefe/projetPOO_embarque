#include <Arduino.h>
#include "IHM.h"

IHM monIHM;
int etat;

void setup()
{
  monIHM.init_IHM();
  Serial.begin(9600);
}
 
void loop()
{
<<<<<<< Updated upstream
//    monIHM.welcome_page();
//    monIHM.allumer_orange(); 
//    monIHM.config_mode();
//    etat = monIHM.button_state();
//    Serial.println("bonjour");

      monIHM.watch_speed();
=======
    //Serial.println("bonjour");
    monIHM.welcome_page();
    monIHM.allumer_orange(); 
    monIHM.config_mode();
    //etat = monIHM.button_state();
    //Serial.println(etat);
    
    
>>>>>>> Stashed changes
}
 
