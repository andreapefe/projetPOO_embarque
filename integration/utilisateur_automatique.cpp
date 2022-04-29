#include "utilisateur_automatique.h"


Utilisateur_automatique::Utilisateur_automatique(){
  set_mode(Automatique);
}

void Utilisateur_automatique::afficherParametres(HardwareSerial * port){
  port->println("Mode Manuel");
}

void Utilisateur_automatique::lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan){
  //Prendre la configuration de la temperature
  temp_voulue = maIHM->choix_temperature();

  current_time = maIHM->choose_time();
  //Boucle controle du ventilateur
  
  
  //Configuration finie donc affichage des configurations choisie
  //monIHM.afficher_temp(0.00);
}
