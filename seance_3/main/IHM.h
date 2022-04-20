#ifndef IHM_H
#define IHM_H

#include <ChainableLED.h>
#include <Arduino.h>
#include <U8g2lib.h>

//led

#define PIN_CLK 3
#define DATA_PIN 4
#define NUMBER_OF_LEDS 1

//potentiomètre

#define ROTARY_ANGLE_SENSOR A0
#define ADC_REF 5 //reference voltage of ADC is 5v.If the Vcc switch on the seeeduino
                    //board switches to 3V3, the ADC_REF should be 3.3
#define GROVE_VCC 5 //VCC of the grove interface is normally 5v
#define FULL_ANGLE 300 //full value of the rotary angle is 300 degree

//bouton poussoir

#define PUSHBUTTON 2

class IHM{

  private:

    ChainableLED * rgb;
    U8G2_SH1107_SEEED_128X128_1_SW_I2C * oled;

  public:

    IHM(); //Constructeur

    ~IHM(); //Destructeur


    //config IHM
    
    void init_IHM();

    //LED RGB

    void allumer_rouge(); //allume la LED en rouge
    void allumer_vert();  //allume la LED en vert
    void allumer_bleu();  //allume la LED en bleu
    void allumer_orange();  //allume la LED en orange
    void eteindre();  //eteindre la LED
    void attendre_2s(); //délais de 2s
    void attendre_1s(); //délais de 1s

    void change_color(float temp); //modifie la couleur de LED en fonction de la température

    //OLED

    void welcome_page();  //affichage écran accueil
    void afficher(u8g2_uint_t x, u8g2_uint_t y, const char* var);  //affichage de "var" à l'écran en (x,y)
    void afficher_temp(float temp);  //afficher la température

    //POTENTIOMETRE

    float poto();
    float get_speed();  //retourne la vitesse du poto

    //POTO + OLED
    
    int config_mode();  //retourne le mode de configuration choisi

    //BOUTON POUSSOIR

    int button_state(); //retourne l'état du bouton poussoir
    
};

#endif
