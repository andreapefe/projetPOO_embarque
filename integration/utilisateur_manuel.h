#ifndef UTILISATEUR_MANUEL_H
#define UTILISATEUR_MANUEL_H

#include "utilisateur.h"
#include <HardwareSerial.h>
#include "IHM.h"
#include "capteur_temp.h"

class Utilisateur_manuel : public Utilisateur {
  
public:
//Constructeurs
  Utilisateur_manuel();

  //Methodes affichage sur le Serial
  void afficherParametres(HardwareSerial * port);

  //Méthodes pour commander le ventilateur

  void lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan);


private:
//Attributs
  
};

#endif
