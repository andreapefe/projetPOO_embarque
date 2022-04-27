#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <HardwareSerial.h>
#include "IHM.h"
#include "definitions.h"
#include "capteur_temp.h"
#include "ventilateur.h"

class Utilisateur{
public:
//Constructeur
  Utilisateur();

//Méthodes pour configurer l'utilisateur
  mode_utilisation get_mode();

  virtual void afficherParametres(HardwareSerial * port)=0;

  void set_mode(mode_utilisation mod);

//Méthodes de lançage

  virtual void lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan)=0;

  

private:
//Attributs
  mode_utilisation modo;   

  
};




#endif
