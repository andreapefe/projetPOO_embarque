#include "temps.h"

//********** CONSTRUCTEURS **************
//Constructeur vide
temps::temps(){
  heure = 0;
  minutes = 0;
}

//Constructeur à partir des int pour les heures et minutes
temps::temps(unsigned long h, unsigned long m){
  heure = h;
  minutes = m;
}

//********** METHODES *******************

//*Debug* : Méthode pour afficher l'heure sur le Serial
void temps::afficher(){
  Serial.print(heure);
  Serial.print(":");
  Serial.println(minutes);
}

//Méthode qui vérifie que la classe temps contient un temps valide
bool temps::verfifier_validite(){
  if (heure > 23 || minutes > 59){
    return false;
  } else {
    return true;
  }
}

//********** OPERATEURS *****************

//Operateur pour à partir d'un tableau de 4 chiffres récupérer le temps en heures et minutes
temps & temps::operator=(std::array<int,TAILLE_TABLEAU_TEMPS>& t){
  this->heure = 10*t.at(0)+t.at(1); 
  this->minutes = 10*t.at(2)+t.at(3);
  return *this; 
}

//Opérateur pour pouvoir comparer deux temps entre heux
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

//Opérateur pour rajouter à un objet de type temps du temps en secondes en effectuant les calcules nécessaires
temps & operator+(temps t, const unsigned long dt){
  Serial.println(dt);
  //Serial.println(dt/3600);
  //On récupére le nombre d'heures à rajouter
  int h_rest = dt/3600;
  t.heure = (t.heure + h_rest); //rajoute les heures directes 
  
  //Vérfiie les minutes à rajouter
  int m_rest = (dt - h_rest*3600) / 60; //en enlève les heures pour voir combien de minutes on rajoute
  
  //On vérifie si le résultat de la somme est supérieur à 60 minutes
  if (t.minutes + m_rest >= 60){
    t.heure += 1; //On rajoute une heure
    t.minutes = (t.minutes + m_rest) % 60; //ajoute minutes module 60
  } else {
    t.minutes = (t.minutes + m_rest); //dans l'autre cas addition directe
  }

  t.heure = t.heure % 24; //On fait modulo 24 pour éviter d'avoir une heure plus grande
  return t;
}
