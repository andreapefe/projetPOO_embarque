#include "IHM.h"
#include "utilisateur.h"
#include "utilisateur_manuel.h"
#include "definitions.h"
#include "capteur_temp.h"

IHM monIHM;
Utilisateur * user;
int incomingByte = 0;
mode_utilisation modo;
bool trouve = false;
capteur_temp cp;
ventilateur vent;

void setup() {
  // put your setup code here, to run once:
  monIHM.init_IHM();
  Serial.begin(9600);
  vent.configuration();
}

void loop() {
  
   // Serial.println("Hola");
   // monIHM.allumer_bleu();
    monIHM.welcome_page();
    modo = monIHM.config_mode();
   

    if (modo == Manuel){
     Utilisateur_manuel * userM = (Utilisateur_manuel *) new Utilisateur_manuel;
     user = userM;
    }else {
      //
      monIHM.select_chiffre();
      Utilisateur_automatique * userA = (Utilsateur_automatique *) new Utilisateur_automatique;
      user = userA;      
    }

  while(1){
    user->lancer(&monIHM, &cp, &vent);
  }
   
  
}
