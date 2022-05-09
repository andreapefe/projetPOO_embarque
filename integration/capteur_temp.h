#ifndef CAPTEUR_TEMP_H
#define CAPTEUR_TEMP_H

#include "definitions.h"
#include <Arduino.h>

#define CAPTEUR_TEMPERATURE A1

class capteur_temp{
  
public:

  //constructeur

  capteur_temp();

  //méthode qui renvoie la température

  float temperature();
  
};


#endif
