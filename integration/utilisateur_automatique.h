#ifndef UTILISATEUR_AUTOMATIQUE_H
#define UTILISATEUR_AUTOMATIQUE_H

#include "utilisateur.h"
#include <HardwareSerial.h>
#include "IHM.h"
#include "capteur_temp.h"
#include "ventilateur.h"
#include "definitions.h"
#include "temps.h"
#include <CurieTime.h>

/* 
 *  Titre : Classe Utilisateur_automatique
 *  Auteur : Andrea Pérez 
 *  Description : Spécialisation de Utilsateur qui défini lancer
 *  pour le mode automatique
 */

#define Gain 15 //correcteur proportionnel
#define HEURE_MAX 20 //Heure max d'utilisation
#define HEURE_MIN 9 //Heure min d'utilisation

class Utilisateur_automatique : public Utilisateur {
  
public:

  //Constructeurs  
  Utilisateur_automatique();

  //Méthode pour commander le ventilateur et lancer l'éxécution du programme 
  void lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan);
  //Méthode pour assigner le mode nuit
  void set_mode_nuit(mode_nuit m);


private:
  //Attributs
  temps current_time; //On rècupère l'heure actuelle
  unsigned long int offset_now; //On récupère le temps interne de l'Arduino pour mettre à zéro
  float temp_voulue; //Température voulue en consigne
  mode_nuit nuit; //Ventilateur actif la nuuit ou pas
  
};

#endif
