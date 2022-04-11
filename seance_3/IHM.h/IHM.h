#include <ChainableLED.h>

#define CLK_PIN 3
#define DATA_PIN 4
#define NUMBER_OF_LEDS 1

#define FISRT_LED 0

#define RED_VALUE 253
#define GREEN_VALUE 0
#define BLUE_VALUE 0

#define NO_LIGHT 0

class IHM{

  private:

    ChainableLED rgb_led(CLK_PIN, DATA_PIN, NUMBER_OF_LEDS);

  public:

    IHM(); //Constructeur
  
    public void initLedRgb();

    public void allumer();

    public void eteindre();

    public void attendre_2s();
};
