#ifndef VENTILATEUR_H
#define VENTILATEUR_H

#define VENTILATEUR_PORT 6

#include <Arduino.h>
#include <cmath>

class ventilateur{
public:
  ventilateur();

  void configuration();
  void set_speed(int v); //set speed between 0 and 100%
  
};

#endif
