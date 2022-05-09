#include "utilisateur.h"

//Constructeur vide
Utilisateur::Utilisateur(){}


//Asseseur pour le mode d'utlisation

mode_utilisation Utilisateur::get_mode(){
  return modo;
}
void Utilisateur::set_mode(mode_utilisation mod){
  modo = mod;
}
