#ifndef VENTILATEUR_H
#define VENTILATEUR_H

#define VENTILATEUR_PORT 6

#include <Arduino.h>
#include <cmath>

#define MAX_VITESSE 300 //valeur max de l'angle atteint par le poto

class ventilateur{
  
public:

  //constructeur
  
  ventilateur();

  //méthodes

  void configuration();
  void set_speed(int v); //set speed between 0 and 100%
  
};

#endif
