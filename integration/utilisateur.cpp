#include "utilisateur.h"

Utilisateur::Utilisateur(){}

mode_utilisation Utilisateur::get_mode(){
  return modo;
}

void Utilisateur::set_mode(mode_utilisation mod){
  modo = mod;
}
