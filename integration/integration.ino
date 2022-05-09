#include "IHM.h"
#include "utilisateur.h"
#include "utilisateur_manuel.h"
#include "definitions.h"
#include "capteur_temp.h"
#include "utilisateur_automatique.h"
#include "temps.h"
#include <array>

/**
 * Titre : Système de contrôle climatique intelligent - iFAN v1
 * Auteurs : Andrea Pérez, Léa Scheer et Christ Mboumba
 * Description : Boucle main du système iFAN v1. Cf le rapport avec ce code pour plus d'information
 */

//Déclaration des objets utilisés
IHM monIHM;
Utilisateur * user; //pointeur de type user pour spécification plus tard
mode_utilisation modo;
capteur_temp cp;
ventilateur vent;

//Mise en place des configurations des périphériques

void setup() {
  monIHM.init_IHM(); //Configuration des composants de l'IHM
  Serial.begin(9600); //Démarrage de la connexion Serial pour debug
  vent.configuration(); //Configuration pour le ventilateur
}

//Boucle infinie
void loop() {

    //Configuration intiale du mode
    monIHM.welcome_page(); //Page de démarrage du système
    delay(2000);
    modo = monIHM.config_mode(); //Récupération du mode d'utilsation
   
    // Création d'un type d'utilisateur qui sera pointé par user
    if (modo == Manuel){
     Utilisateur_manuel * userM = (Utilisateur_manuel *) new Utilisateur_manuel;
     user = userM;
    }else {
      Utilisateur_automatique * userA = (Utilisateur_automatique *) new Utilisateur_automatique;
      user = userA; 
    }

    //Lancement du programme principal
    user->lancer(&monIHM, &cp, &vent);


    //Sortie de boucle (Buton CANCEL)
    //Réinitialisation LED et ventilateur avant redémarrage
    vent.set_speed(0);
    monIHM.eteindre();
    
}
