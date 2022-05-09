#ifndef IHM_H
#define IHM_H

#include <ChainableLED.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <array>
#include "definitions.h"
#include "temps.h"

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
    void allumer_bleu();  //allume la LED en bleu
    void allumer_orange();  //allume la LED en orange
<<<<<<< Updated upstream
    void eteindre();  //eteindre la LED
    void led_change_couleur(float temp);  //change couleur led en fonction de la temp
=======
    void allumer_rouge_intense(); //fait cligniter le led en rouge
    void eteindre();  //eteindre la LED
>>>>>>> Stashed changes

    //OLED

    void welcome_page();  //affichage écran accueil

<<<<<<< Updated upstream
    int select_chiffre(int i, std::array<int, 4>& t);  //pour modifier un chiffre de 0 à 9
=======
    void afficher_vitesse();  //afficher la vitesse à l'écran

    int select_chiffre(int i, int * t);  //pour modifier un chiffre de 0 à 9
>>>>>>> Stashed changes

    temps choose_time(); //utilisateur choisit l'heure

    mode_nuit choose_night_mode();  //utilisateur choisit mode nuit pas

    void effacer_oled();

<<<<<<< Updated upstream
    void page_resume_mode_autom(float temp_voulue, mode_nuit m); //resume les specifications du mode automatique choisies par l'utilisateur
=======
    float get_speed(); //renvoie valeur du potentiomètre (vitesse ventilateur)
>>>>>>> Stashed changes

    mode_utilisation config_mode();  //retourne le mode de configuration choisi

    void watch_speed(float vitesse); //visualisation graphique de la vitesse du ventilateur

    float choix_temperature();  //choix de la température par l'utilisateur
    
    //POTENTIOMETRE

    float get_speed();  //retourne la vitesse du poto
    
    //BOUTON POUSSOIR

    bool button_state(); //retourne l'état du bouton poussoir

};

#endif
