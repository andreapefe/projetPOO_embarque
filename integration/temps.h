#ifndef TEMPS_H
#define TEMPS_H

//Pour affichage simple température
#define TAILLE_TABLEAU_TEMPS 4

#include <array>
#include <Arduino.h>

class temps{
  
public:

  //constructeurs

  temps();

  temps(unsigned long h, unsigned long m);

  //méthodes

  void afficher();
  bool verfifier_validite();  //verifier que l'heure est possible

  //Operateur pour à partir d'un tableau de 4 chiffres récupérer le temps
  
  temps & operator=(std::array<int,TAILLE_TABLEAU_TEMPS>& t);

  //attributs

  unsigned long heure;
  unsigned long minutes;
};

bool operator<(temps t, temps dt);  //redéfinition de l'opérateur <

temps & operator+(temps t, const unsigned long dt); //redéfinition de l'opérateur +

#endif
