#include "utilisateur_automatique.h"


Utilisateur_manuel::Utilisateur_automatique(){
  set_mode(Automatique);
}

void Utilisateur_automatique::afficherParametres(HardwareSerial * port){
  port->println("Mode Manuel");
}
