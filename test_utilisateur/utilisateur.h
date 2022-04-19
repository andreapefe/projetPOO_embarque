#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <HardwareSerial.h>

//Mode Possibles d'utilisation du 
enum mode_utilisation {Manuel, Automatique};


class Utilisateur{
public:
//Constructeur
  Utilisateur();

//Méthodes pour configurer l'utilisateur
  mode_utilisation get_mode();

  virtual void afficherParametres(HardwareSerial * port);

  void set_mode(mode_utilisation mod);

//Méthodes pour afficher sur le IHM
  virtual void afficherInit();
  

private:
//Attributs
  mode_utilisation modo;   

  
};




#endif
