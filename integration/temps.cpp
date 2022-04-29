#include "temps.h"

temps::temps(){
  heure = 0;
  minutes = 0;
  secondes_total = 0;
}

temps & temps::operator=(const int * t){
  this->heure = 10*t[0]+t[1];
  this->minutes = 10*t[2]+t[3];
  return *this; 
}
