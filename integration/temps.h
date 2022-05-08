#ifndef TEMPS_H
#define TEMPS_H

//Pour affichage simple température
#define TAILLE_TABLEAU_TEMPS 4

#include <array>
#include <Arduino.h>

class temps{
public:
  temps();

  temps(unsigned long h, unsigned long m);

  void afficher();
  //Operateur pour à partir d'un tableau de 4 chiffres récupérer le temps
  temps & operator=(std::array<int,TAILLE_TABLEAU_TEMPS>& t);

  temps & operator-=(const unsigned long s);

  temps & operator+=(const unsigned long s);

  bool verfifier_validite();

  unsigned long heure;
  unsigned long minutes;
};

bool operator<(temps t, temps dt);

temps & operator+(temps t, const unsigned long dt);

#endif
