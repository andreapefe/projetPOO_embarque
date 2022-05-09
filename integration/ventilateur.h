#ifndef VENTILATEUR_H
#define VENTILATEUR_H

#include <Arduino.h>
#include <cmath>

/* 
 *   Titre : Classe Ventilateur
 *  Auteur : Andrea Pérez et Christ Mboumba
 *  Description : Classe pour lire fixer la PWM sur le pin D6 et contrôler
 *  le ventilateur en vitesse
 */

#define VENTILATEUR_PORT 6
#define MAX_VITESSE 300 //valeur max de l'angle atteint par le poto

class ventilateur{
  
public:

  //Constructeur
  ventilateur();

  //Méthode qui configure la sortie D6 en PWM
  void configuration();

  //Méthode qui fixe le rapport PWM en fonction de l'entrée en %
  void set_speed(int v); //set speed between 0 and 100%
  
};

#endif
