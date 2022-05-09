#ifndef UTILISATEUR_MANUEL_H
#define UTILISATEUR_MANUEL_H

#include "utilisateur.h"
#include <HardwareSerial.h>
#include "IHM.h"
#include "capteur_temp.h"
#include "ventilateur.h"

class Utilisateur_manuel : public Utilisateur {
  
public:

  //Constructeurs
  
  Utilisateur_manuel();

  //Méthode pour commander le ventilateur avec le potentiomètre
  void lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan);
  
};

#endif
