#ifndef UTILISATEUR_H
#define UTILISATEUR_H

//Mode Possibles d'utilisation du 
enum mode_utilisation {Manuel, Automatique};


class Utilisateur{
public:
//Constructeur
  Utilisateur();

//Méthodes
  mode_utilisation get_mode();

  virtual void afficherParametres();

  void set_mode(mode_utilisation mod);
  

private:
//Attributs
  mode_utilisation modo;   

  
};




#endif
