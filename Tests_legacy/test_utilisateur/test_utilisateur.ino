#include "utilisateur.h"
#include "utilisateur_manuel.h"

HardwareSerial *mySerial = &Serial;

void setup() {
  // put your setup code here, to run once:
  Utilisateur * A;
  A = new Utilisateur_manuel[0]; 
  mySerial->begin(9600);
  A->afficherParametres(mySerial);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
}
