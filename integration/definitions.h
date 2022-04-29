#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//Mode Possibles d'utilisation du ventilateur
enum mode_utilisation {Manuel, Automatique, NonDemarre};

//Pour affichage simple température
struct temps {
  unsigned long heure;
  unsigned long minutes;
};






#endif 
