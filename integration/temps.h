#ifndef TEMPS_H
#define TEMPS_H

//Pour affichage simple température
#define TAILLE_TABLEAU_TEMPS 4

#include <stdexcept>
#include <Arduino.h>

class temps{
public:
  temps();

  void afficher();

  temps & operator=(const int * t);

  temps & operator-=(const unsigned long s);

  temps & operator+=(const unsigned long s);

private:
  unsigned long heure;
  unsigned long minutes;
};

#endif
