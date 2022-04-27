#include "ventilateur.h"

ventilateur::ventilateur(){
  
}

void ventilateur::configuration(){
  pinMode(VENTILATEUR_PORT, OUTPUT);
}

void ventilateur::set_speed(int v){
  //map 0 to 100% to an int between 0 and 255
  int rapportCycliqueEntre0et255 = map(v, 0, 100, 0, 255);
   Serial.println(rapportCycliqueEntre0et255);
  analogWrite(VENTILATEUR_PORT, rapportCycliqueEntre0et255);
}
