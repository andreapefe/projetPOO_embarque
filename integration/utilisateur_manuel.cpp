#include "utilisateur_manuel.h"

Utilisateur_manuel::Utilisateur_manuel(){
  set_mode(Manuel);
}

void Utilisateur_manuel::afficherParametres(HardwareSerial * port){
  port->println("Mode Automatique");
}
