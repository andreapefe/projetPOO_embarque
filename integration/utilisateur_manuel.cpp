#include "utilisateur_manuel.h"

//Constructeur
Utilisateur_manuel::Utilisateur_manuel(){
  set_mode(Manuel);
}

//Lance le mode manuel dans ce cas
void Utilisateur_manuel::lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan){

  maIHM->effacer_oled();
  delay(100);
  
// attendre button cancel 
  while(!(maIHM->button_state())){
  
   //On récupère la vitesse du potentiomètre
   float v = (maIHM->get_speed())/MAX_VITESSE*100;
   
   //On fixe la vitesse du ventilateur 
   fan->set_speed(round(v));
  
   //On affiche la vitesse par une jauge qui augmente avec la puissance
   maIHM->watch_speed(v);
 }
 
}
