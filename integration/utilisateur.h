#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "IHM.h"
#include "definitions.h"
#include "capteur_temp.h"
#include "ventilateur.h"
#include "temps.h"

/* 
 *  Titre : Classe virtuelle Utilisateur
 *  Auteur : Andrea Pérez 
 *  Description : Classe virtuelle qui défini une méthode virtuelle pour lancer
 *  l'éxécution du programme de contrôle du ventilateur
 */

class Utilisateur{
  
public:

  //Constructeur
  Utilisateur();

  //Asseseur pour configurer l'utilisateur
  mode_utilisation get_mode();  //récupérer le mode choisit par l'utilisateur pour l'afficher après
  void set_mode(mode_utilisation mod);  //configurer le mode voulu par l'utilisateur

  //Méthode de lancement du programme
  virtual void lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan)=0;
  
private:

  //mode utilisation automatique ou manuel
  mode_utilisation modo;   

};

#endif
