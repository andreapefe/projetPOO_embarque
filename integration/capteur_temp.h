#ifndef CAPTEUR_TEMP_H
#define CAPTEUR_TEMP_H

#include "definitions.h"
#include <Arduino.h>

#define CAPTEUR_TEMPERATURE A1

class capteur_temp{
public:
  capteur_temp();

  float temperature();
  
};


#endif
