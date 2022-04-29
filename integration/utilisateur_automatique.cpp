#include "utilisateur_automatique.h"


Utilisateur_automatique::Utilisateur_automatique(){
  set_mode(Automatique);
}

void Utilisateur_automatique::afficherParametres(HardwareSerial * port){
  port->println("Mode Manuel");
}

void Utilisateur_automatique::set_mode_nuit(mode_nuit m){
  nuit = m;
}

void Utilisateur_automatique::lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan){
  //Prendre la configuration de la temperature
  temp_voulue = maIHM->choix_temperature();

  current_time = maIHM->choose_time();
  //Configuration mode nuit
  set_mode_nuit(maIHM->choose_night_mode());
  
  //Boucle controle du ventilateur
  
  
  //Configuration finie donc affichage des configurations choisie
  //monIHM.afficher_temp(0.00);
}
