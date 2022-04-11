#include <ChainableLED.h>

#include <IHM.h>

#define CLK_PIN 3
#define DATA_PIN 4
#define NUMBER_OF_LEDS 1

#define RED_VALUE 253
#define GREEN_VALUE 0
#define BLUE_VALUE 0

class IHM{

  private:

    ChainableLED rgb_led(CLK_PIN, DATA_PIN, NUMBER_OF_LEDS);

  public:

    IHM(); //Constructeur
  
    public void initLedRgb(); //initialiser la led RGB

    public void allumer();  //allumer la led RGB

    public void eteindre(); //éteindre la led RGB

    public void attendre_2s(); //attendre 5 secondes avant nouvelle commande
};


IHM :: initLedRgb(){
  rgb_led.init();
}

IHM :: allumer(){
  rgb_led.setColorRGB(FIRST_LED,RED_VALUE,GREEN_VALUE,BLUE_VALUE);
}

IHM :: eteindre(){
  rgb_led.setColorRGB(FIRST_LED,NO_LIGHT,NO_LIGHT,NO_LIGHT);
}

IHM :: attendre_2s(){
  delay(2000)
}
