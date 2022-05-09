#include "utilisateur_automatique.h"

//Constructeur qui fixe le mode Automatique
Utilisateur_automatique::Utilisateur_automatique(){
  set_mode(Automatique);
}

//Méthode pour fixer le mode nuit souhaité
void Utilisateur_automatique::set_mode_nuit(mode_nuit m){
  nuit = m;
}

//Méthode (spécialisation de fonction virtuelle) qui permet d'éxécuter le code principale de contrôl
void Utilisateur_automatique::lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan){
  
  //Prendre la configuration de la temperature voulue
  temp_voulue = maIHM->choix_temperature();
  
  //Configuration mode nuit
  nuit = maIHM->choose_night_mode();

  //En cas que le ventilateur ne doivent pas être activé la nuit
  if (nuit == Nuit_non){
    
    //Récupérer l'heure actuelle
    current_time = maIHM->choose_time(); //Utilisateur rentre heure
    offset_now = now(); //On récupère le temps du microcontrolleur pour faire la mise à zéro
    current_time.afficher(); //*Debug* : Afficher sur le Serial pour vérfier que l'heure a bien été prise en compte

    //Calcul de l'heure actuelle 
    temps mtn; 
    unsigned long int offset = now() - offset_now; //Temps passé depuis que l'heure a été configuré
    Serial.println(offset); //*Debug* : Afficher le temps écoulé
    mtn = current_time + offset; //Rajout du temps écoulé en secondes au temps fixé
    mtn.afficher();

    //Fixer les constantes de temps hors service  
    const temps temps_limite(HEURE_MAX,0); //À partir de 20h le ventilateur s'éteint
    const temps temps_limite_bas(HEURE_MIN,0); //Avant 9h ne fonctionne pas
    delay(300);
    
    //Afficher sur OLED de la configuration choisie
    maIHM->effacer_oled();
    maIHM->page_resume_mode_autom(temp_voulue, nuit);
    
    //Boucle controle du ventilateur (Correcteur P) quand le ventilateur s'éteint la nuit
    //On vérifie que nous sommes à la bonne heure et que le bouton cancel n'a pas été utilisé
    while(mtn < temps_limite && !(maIHM->button_state()) && !(mtn<temps_limite_bas)){
      
      //Récupérer température pour calcul de l'erreur
      float temp_act = cp->temperature();
      int erreur = (int)(temp_act - temp_voulue);
      
      // Récupérer heure actuelle
      offset = now() - offset_now;
      mtn = current_time + offset;
      mtn.afficher();

      //Saturation du ventilateur à 100% de vitesse et à 0 pour les consignes négatives
      if (Gain*erreur < 100 && Gain*erreur > 0){
        fan->set_speed(Gain*erreur);
      } else if (Gain*erreur < 0){
        fan->set_speed(0); //On ne peut pas rechauffer avec un ventilateur
      } else {
        fan->set_speed(100); //Saturation
      }
      //Afficher sur OLED de la configuration choisie
      maIHM->page_resume_mode_autom(temp_voulue, nuit);
      //Couleur de la LED change en fonction de la température
      maIHM->led_change_couleur(temp_act);
    }   
  } 
  
  // En cas que le ventilateur soit activé la nuit
  else {
    
    //Afficher sur OLED de la configuration choisie
    maIHM->effacer_oled();
    maIHM->page_resume_mode_autom(temp_voulue, nuit);
    
    //Boucle controle du ventilateur (Correcteur P)
    while(!maIHM->button_state()){ 
      //Récupérer température pour calcul de l'erreur
      float temp_act = cp->temperature();
      int erreur = (int)(temp_act - temp_voulue);

      //Saturation du ventilateur à 100% de vitesse et à 0 pour les consignes négatives
      if (Gain*erreur < 100 && Gain*erreur > 0){
        fan->set_speed(Gain*erreur);
      } else if (Gain*erreur < 0){
        fan->set_speed(0); //On ne peut pas rechauffer avec un ventilateur
      } else {
        fan->set_speed(100); //Saturation
      }
      
      //Afficher sur OLED de la configuration choisie
      maIHM->page_resume_mode_autom(temp_voulue, nuit);
      maIHM->led_change_couleur(temp_act);
    }
  }
}
