#ifndef UTILISATEUR_AUTOMATIQUE_H
#define UTILISATEUR_AUTOMATIQUE_H

#include "utilisateur.h"
#include <HardwareSerial.h>
#include "IHM.h"
#include "capteur_temp.h"
#include "ventilateur.h"
#include "definitions.h"
#include "temps.h"
#include <CurieTime.h>

#define Gain 15 //correcteur proportionnel

class Utilisateur_automatique : public Utilisateur {
  
public:

  //Constructeurs
  
  Utilisateur_automatique();

  //Methodes affichage sur le Serial
  
  void afficherParametres(HardwareSerial * port);

  //Méthodes pour commander le ventilateur

  void lancer(IHM * maIHM, capteur_temp * cp, ventilateur * fan);
  void set_mode_nuit(mode_nuit m);


private:
  
  //Attributs
  
  temps current_time;
  unsigned long int offset_now;
  float temp_voulue;
  mode_nuit nuit;
  
};

#endif
