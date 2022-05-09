#include "ventilateur.h"

//Constructeur vide
ventilateur::ventilateur(){
  
}

//Méthode pour configurer le pin D6 en PWM
void ventilateur::configuration(){
  pinMode(VENTILATEUR_PORT, OUTPUT);
}

//Méthode qui fixe le rapport PWM en fonction de l'entrée en %
void ventilateur::set_speed(int v){
  //map 0 to 100% to an int between 0 and 255
  int rapportCycliqueEntre0et255 = map(v, 0, 100, 0, 255);
  analogWrite(VENTILATEUR_PORT, rapportCycliqueEntre0et255);
}
