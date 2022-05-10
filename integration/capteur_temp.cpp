#include "capteur_temp.h"

//Constructeur vide
capteur_temp::capteur_temp(){}
 
//Méthode qui renvoie la température
float capteur_temp::temperature(){
  //constant values
  const int R0 = 100000; 
  const int B = 4275;   
  //Get integer value from sensor (cf. https://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/ )
  int a = analogRead(CAPTEUR_TEMPERATURE);
  // Transform to actual float value
  float R = 1023.0/a-1.0;
  R = R0*R;
  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
  temperature -= 25;
  Serial.println(temperature);
  return temperature;
}
