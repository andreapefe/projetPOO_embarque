#include "IHM.h"
#include "utilisateur.h"
#include "utilisateur_manuel.h"
#include "definitions.h"

IHM monIHM;
Utilisateur * user;
int incomingByte = 0;
mode_utilisation modo;
bool trouve = false;


void setup() {
  // put your setup code here, to run once:
  monIHM.init_IHM();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!trouve){
    if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
      if (incomingByte == 13){trouve = true;}
    }
    Serial.println("Start");
    modo = monIHM.config_mode();
  } 
  
}
