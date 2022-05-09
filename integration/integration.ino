#include "IHM.h"
#include "utilisateur.h"
#include "utilisateur_manuel.h"
#include "definitions.h"
#include "capteur_temp.h"
#include "utilisateur_automatique.h"
#include "temps.h"
#include <array>

IHM monIHM;
Utilisateur * user;
int incomingByte = 0;
mode_utilisation modo;
bool trouve = false;
capteur_temp cp;
ventilateur vent;

void setup() {

  monIHM.init_IHM();
  Serial.begin(9600);
  vent.configuration();
  
}

void loop() {

    monIHM.welcome_page();
    delay(2000);
    modo = monIHM.config_mode();
   

    if (modo == Manuel){
     Utilisateur_manuel * userM = (Utilisateur_manuel *) new Utilisateur_manuel;
     user = userM;
    }else {
      Utilisateur_automatique * userA = (Utilisateur_automatique *) new Utilisateur_automatique;
      user = userA; 
    }
    user->lancer(&monIHM, &cp, &vent);

    //réinitialisation LED et ventilateur
    
    vent.set_speed(0);
    monIHM.eteindre();
}
