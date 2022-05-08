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
    //Définir le temps actuel
    current_time = maIHM->choose_time();
    offset_now = now();
    current_time.afficher();

    //Pour calculer le vrai temps
    temps mtn;
    unsigned long int offset = now() - offset_now;
    Serial.println(offset);
    mtn = current_time + offset;
    mtn.afficher();
    temps temps_limite(20,0); //À partir de 20h le ventilateur s'éteint
    temps temps_limite_bas(9,0); //Avant 9h ne fonctionne pas
    delay(300);
    maIHM->effacer_oled();
    maIHM->page_resume_mode_autom(temp_voulue, nuit);
    
    //Boucle controle du ventilateur (Correcteur P) quand le ventilateur s'éteint la nuit
    while(mtn < temps_limite && !(maIHM->button_state()) && !(mtn<temps_limite_bas)){
      //Récupérer température pour erreur
      float temp_act = cp->temperature();
      int erreur = (int)(temp_act - temp_voulue);
      Serial.println("Dedans");
      // Récupérer heure actuelle
      offset = now() - offset_now;
      mtn = current_time + offset;
      mtn.afficher();
      if (Gain*erreur < 100 && Gain*erreur > 0){
        fan->set_speed(Gain*erreur);
      } else if (Gain*erreur < 0){
        fan->set_speed(0); //On ne peut pas rechauffer avec un ventilateur
      } else {
        fan->set_speed(100); //Saturation
      }
      maIHM->page_resume_mode_autom(temp_voulue, nuit);
      maIHM->led_change_couleur(temp_act);
    }
      
  } else {
    maIHM->effacer_oled();
    maIHM->page_resume_mode_autom(temp_voulue, nuit);
    
    //Boucle controle du ventilateur (Correcteur P)
    while(!maIHM->button_state()){ 
      float temp_act = cp->temperature();
      int erreur = (int)(temp_act - temp_voulue);
      if (Gain*erreur < 100 && Gain*erreur > 0){
        fan->set_speed(Gain*erreur);
      } else if (Gain*erreur < 0){
        fan->set_speed(0); //On ne peut pas rechauffer avec un ventilateur
      } else {
        fan->set_speed(100); //Saturation
      }
      maIHM->page_resume_mode_autom(temp_voulue, nuit);
      maIHM->led_change_couleur(temp_act);
    }
  }
}
