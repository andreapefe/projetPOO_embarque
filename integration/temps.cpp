#include "temps.h"

temps::temps(){
  heure = 0;
  minutes = 0;
}

temps::temps(unsigned long h, unsigned long m){
  heure = h;
  minutes = m;
}

temps & temps::operator=(std::array<int,TAILLE_TABLEAU_TEMPS>& t){
  this->heure = 10*t.at(0)+t.at(1);
  this->minutes = 10*t.at(2)+t.at(3);
  return *this; 
}

void temps::afficher(){
  Serial.print(heure);
  Serial.print(":");
  Serial.println(minutes);
}

bool operator<(temps t, temps dt){
  bool retour;
  if (t.heure < dt.heure){
    retour = true;
  } else if (t.minutes < dt.minutes && t.heure == dt.heure){
    retour = true;
  } else {
    retour = false;
  }
  return retour;
}

temps & operator+(temps t, const unsigned long dt){
  Serial.println(dt);
  //Serial.println(dt/3600);
  int h_rest = dt/3600;
  t.heure = (t.heure + h_rest); //rajoute les heures directes
  //Vérfiie les minutes à rajouter
  int m_rest = (dt - h_rest*3600) / 60;
  //Serial.println(m_rest);
  if (t.minutes + m_rest >= 60){
    t.heure += 1;
    t.minutes = (t.minutes + m_rest) % 60;
  } else {
    t.minutes = (t.minutes + m_rest);
  }
  //Serial.println(t.minutes);
  t.heure = t.heure % 24;
  return t;
}

bool temps::verfifier_validite(){
  if (heure > 23 || minutes > 59){
    return false;
  } else {
    return true;
  }
}
