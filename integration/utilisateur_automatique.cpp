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
  //Prendre la configuration de la temperature voulue
  temp_voulue = maIHM->choix_temperature();

  //Configuration mode nuit
  nuit = maIHM->choose_night_mode();
  if (nuit == Nuit_non){
    current_time = maIHM->choose_time();
    current_time -= now();
   // current_time.afficher(current_time += now());
  } else {
    //Boucle controle du ventilateur (Correcteur P)
  while(temp_voulue != cp->temperature()){
    int erreur = (int)(cp->temperature()- temp_voulue);
    if (Gain*erreur < 100 && Gain*erreur > 0){
      fan->set_speed(Gain*erreur);
    } else if (Gain*erreur < 0){
      fan->set_speed(0); //On ne peut pas rechauffer avec un ventilateur
    } else {
      fan->set_speed(100); //Saturation
    }
  }
  
  
  }
  
  //Configuration finie donc affichage des configurations choisie
  //monIHM.afficher_temp(0.00);
}
