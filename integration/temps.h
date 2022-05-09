#ifndef TEMPS_H
#define TEMPS_H

#include <array>
#include <Arduino.h>

/* 
 *  Titre : Classe Temps
 *  Auteur : Andrea Pérez 
 *  Description : Classe pour afficher, gérer et transformer des secondes en 
 *  heures en format 24h. 
 */

#define TAILLE_TABLEAU_TEMPS 4 //Taille des valeurs à donner

class temps{
  
public:

  //Constructeurs
  temps(); //Constructeur vide
  temps(unsigned long h, unsigned long m); //Constructeur à partir des int pour les heures et minutes

  //*Debug* : Méthode pour afficher l'heure sur le Serial
  void afficher();
  //Méthode qui vérifie que la classe temps contient un temps valide
  bool verfifier_validite();  //verifier que l'heure est possible

  //Operateur pour à partir d'un tableau de 4 chiffres récupérer le temps en heures et minutes
  temps & operator=(std::array<int,TAILLE_TABLEAU_TEMPS>& t);

  //Attributs
  unsigned long heure;
  unsigned long minutes;
};

//Opérateur pour pouvoir comparer deux temps entre heux
bool operator<(temps t, temps dt);  //redéfinition de l'opérateur <

//Opérateur pour rajouter à un objet de type temps du temps en secondes en effectuant les calcules nécessaires
temps & operator+(temps t, const unsigned long dt); //redéfinition de l'opérateur +

#endif
