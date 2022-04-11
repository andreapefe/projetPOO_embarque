#ifndef IHM_H
#define IHM_H

#include <ChainableLED.h>
#include <Arduino.h>

#define PIN_CLK 3
#define DATA_PIN 4
#define NUMBER_OF_LEDS 1

class IHM{

  private:

    ChainableLED * rgb;

  public:

    IHM(); //Constructeur
  
    void initLedRgb();

    void allumer_rouge();

    void allumer_vert();

    void eteindre();

    void attendre_2s();
};

#endif
