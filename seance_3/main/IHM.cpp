#include "IHM.h"

IHM::IHM(){
  rgb = new ChainableLED(PIN_CLK,DATA_PIN,NUMBER_OF_LEDS);
}

void IHM :: initLedRgb(){
  rgb->init();
}

void IHM :: allumer_rouge(){
  rgb->setColorRGB(0,253,0,0);
}

void IHM :: allumer_vert(){
  rgb->setColorRGB(0,0,253,0);
}

void IHM :: allumer_bleu(){
  rgb->setColorRGB(0,0,0,253);
}

void IHM :: eteindre(){
  rgb->setColorRGB(0,0,0,0);
}

void IHM :: attendre_2s(){
  delay(2000);
}

void IHM :: attendre_1s(){
  delay(1000);
}
