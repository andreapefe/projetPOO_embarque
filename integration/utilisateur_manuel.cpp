#include "utilisateur_manuel.h"

Utilisateur_manuel::Utilisateur_manuel(){
  set_mode(Manuel);
}
void Utilisateur_manuel::afficherParametres(HardwareSerial * port){
  port->println("Mode Manuel");
}

//Lance le mode manuel dans ce cas

void Utilisateur_manuel::lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan){
 //maIHM->afficher_temp(cp->temperature());
 float v = (maIHM->get_speed())/MAX_VITESSE*100;
 fan->set_speed(round(v));
 maIHM->watch_speed(v);
 
}
