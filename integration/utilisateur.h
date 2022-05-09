#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <HardwareSerial.h>
#include "IHM.h"
#include "definitions.h"
#include "capteur_temp.h"
#include "ventilateur.h"
#include "temps.h"

class Utilisateur{
  
public:

  //Constructeur
  
  Utilisateur();

  //Méthodes pour configurer l'utilisateur
  
  mode_utilisation get_mode();  //récupérer le mode choisit par l'utilisateur pour l'afficher après

  virtual void afficherParametres(HardwareSerial * port)=0;

  void set_mode(mode_utilisation mod);  //configurer le mode voulu par l'utilisateur

  //Méthode de lancement du programme

  virtual void lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan)=0;
  
private:

  //Attribut
  
  mode_utilisation modo;   

};

#endif
