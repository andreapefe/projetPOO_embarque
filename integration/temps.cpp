#include "temps.h"

temps::temps(){
  heure = 0;
  minutes = 0;
}

temps & temps::operator=(const int * t){
  this->heure = 10*t[0]+t[1];
  this->minutes = 10*t[2]+t[3];
  return *this; 
}

temps & temps::operator-=(const unsigned long s){
  this->heure = (heure - (s % 3600))%24;
  minutes = (minutes - (s % 60))%60;
  return *this;
}

temps & temps::operator+=(const unsigned long s){
  this->heure = (heure + (s % 3600))%24;
  minutes = (minutes + (s % 60))%60;
  return *this;
}

void temps::afficher(){
  Serial.print(heure);
  Serial.print(":");
  Serial.println(minutes);
}
