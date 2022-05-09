#ifndef CAPTEUR_TEMP_H
#define CAPTEUR_TEMP_H

#include "definitions.h"
#include <Arduino.h>

/* 
 *  Titre : Classe Capteur température  
 *  Auteur : Andrea Pérez et Christ Mboumba
 *  Description : Classe pour lire la température avec un capteur de température 
 *  Groove Seed sur le pin A1
 */

#define CAPTEUR_TEMPERATURE A1

class capteur_temp{
  
public:

  //Constructeur
  capteur_temp();

  //Méthode qui renvoie la température
  float temperature();
  
};


#endif
