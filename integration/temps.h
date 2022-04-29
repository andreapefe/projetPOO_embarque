#ifndef TEMPS_H
#define TEMPS_H

//Pour affichage simple température
#define TAILLE_TABLEAU_TEMPS 4

class temps{
public:
  temps();

  temps operator=(int * t);

private:
  unsigned long heure;
  unsigned long minutes;

  unsigned long secondes_total;

};

#endif
