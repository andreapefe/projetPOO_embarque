#include "utilisateur_manuel.h"

Utilisateur_manuel::Utilisateur_manuel(){
  set_mode(Manuel);
}
void Utilisateur_manuel::afficherParametres(HardwareSerial * port){
  port->println("Mode Manuel");
}

//Lance le mode manuel dans ce cas

void Utilisateur_manuel::lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan){
 maIHM->afficher_temp(cp->temperature());
 fan->set_speed(50);
}
