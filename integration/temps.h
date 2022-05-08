#ifndef TEMPS_H
#define TEMPS_H

//Pour affichage simple température
#define TAILLE_TABLEAU_TEMPS 4

#include <stdexcept>
#include <Arduino.h>

class temps{
public:
  temps();

  temps(unsigned long h, unsigned long m);

  void afficher();

  temps & operator=(const int * t) throw (std::range_error); //Range errors : result of the computation cannot be represented by the destination type temps. (heure > 24)

  temps & operator-=(const unsigned long s);

  temps & operator+=(const unsigned long s);

  unsigned long heure;
  unsigned long minutes;
};

bool operator<(temps t, temps dt);

temps & operator+(temps t, const unsigned long dt);

#endif
