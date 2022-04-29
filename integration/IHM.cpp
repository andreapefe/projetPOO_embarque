#include "IHM.h"

IHM::IHM(){
  rgb = new ChainableLED(PIN_CLK,DATA_PIN,NUMBER_OF_LEDS);
  oled = new U8G2_SH1107_SEEED_128X128_1_SW_I2C(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
}

IHM :: ~IHM(){}

void IHM :: init_IHM(){
  rgb->init();  //led rgb
  oled -> begin();  //écran oled
  //Serial.begin(9600);
  Serial.begin(9600);
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);  //poto
  pinMode(PUSHBUTTON, INPUT); //bouton poussoir
}


////////////////////// LED ////////////////////////////////


void IHM :: allumer_rouge(){
  rgb->setColorRGB(0,253,0,0);
}

void IHM :: allumer_vert(){
  rgb->setColorRGB(0,0,253,0);
}

void IHM :: allumer_bleu(){
  rgb->setColorRGB(0,0,0,253);
}

void IHM :: allumer_orange(){
  rgb->setColorRGB(0,255,140,0);
}

void IHM :: allumer_rouge_intense(){
  rgb->setColorRGB(0,253,0,0);
  rgb->setColorHSL(0,1,1,1);
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

////////////////////// OLED ////////////////////////////////

void IHM :: afficher(u8g2_uint_t x, u8g2_uint_t y, const char* var){
  oled -> firstPage();
  do {
    oled -> setFont(u8g2_font_ncenB10_tr);
    oled -> drawStr(x,y,var);
  } while (oled -> nextPage());
}

void IHM :: welcome_page(){
  float angle = this -> poto();
  
  oled -> firstPage();
  do {
    oled -> setFont(u8g2_font_ncenB10_tr);
    oled -> drawStr(0,24,"BONJOUR");
    oled -> drawStr(0,50,"SELECT MODE :");
    oled -> drawStr(0,100, "Angle : ");
    oled -> drawStr(55,100,String(angle).c_str());
  } while (oled -> nextPage());
}



void IHM :: afficher_temp(float temp){
  oled -> firstPage();
    do {
      oled -> setFont(u8g2_font_ncenB10_tr);
      oled -> drawStr(50,50,String(temp).c_str());
    } while (oled -> nextPage());
}

int IHM :: select_chiffre(){

  int chiffre = 0;
  float angle = this->poto(); //récupérer valeur potentiomètre
  
  oled -> clearDisplay();  //effacer écran

  while(!this->button_state()){
    angle = this->poto(); 

    oled -> firstPage();
  
    do {
  
      oled -> setFont(u8g2_font_ncenB10_tr);
      oled -> drawStr(0,24,"Chiffre choisi :");
      oled -> drawStr(0,60, String(chiffre).c_str());
      
      if(angle >= 0 && angle < 30){
        chiffre = 0;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 30 && angle < 60){
        chiffre = 1;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 60 && angle < 90){
        chiffre = 2;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 90 && angle < 120){
        chiffre = 3;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 120 && angle < 150){
        chiffre = 4;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 150 && angle < 180){
        chiffre = 5;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 180 && angle < 210){
        chiffre = 6;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 210 && angle < 240){
        chiffre = 7;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 240 && angle < 270){
        chiffre = 8;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }else if(angle >= 270 && angle < 300){
        chiffre = 9;
        oled -> drawStr(0,60,String(chiffre).c_str());
      }
    }while (oled -> nextPage());    
  }
}



////////////////////// POTO ////////////////////////////////

float IHM :: poto(){
  
  float voltage;
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  voltage = (float)sensor_value*ADC_REF/1023;
  float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;
  //Serial.println("The angle between the mark and the starting position:");
  //Serial.println(degrees);

  return degrees;
}

float IHM :: get_speed(){
  return this -> poto();
}


////////////////////// POTO + OLED ////////////////////////////////

mode_utilisation IHM :: config_mode(){
   oled -> clearDisplay();  //effacer écran

   float angle = this->poto(); //récupérer valeur potentiomètre

   while(!this->button_state()){
    angle = this -> poto(); //récupérer valeur potentiomètre

    oled -> firstPage();
    do {
      oled -> setFont(u8g2_font_ncenB10_tr);
      oled -> drawStr(10,25,"Automatique");
      oled -> drawStr(10,80,"Manuel");
      if(angle < 150){                //en haut
        oled -> drawHLine(10,26,100); //ligne horizontale (x,y,longueur) qui souligne mode automatique
      }else{                          //en bas
        oled -> drawHLine(10,81,55);  //ligne horizontale (x,y,longueur) qui souligne mode manuel
      }
    } while (oled -> nextPage());

   }
   if (angle < 150){
      return Automatique;
   } else {
    return Manuel;
   }
   oled -> clearDisplay();
}

void IHM :: watch_speed(float vitesse){
  oled -> firstPage();
  do {
    oled -> drawRFrame(0,60,100,10,0); //(x,y,largeur,hauteur,arrondi des angles)
    if( vitesse < 10){
      oled -> drawBox(0,60,10,10);
    }else if(vitesse >= 10 && vitesse < 20){
      oled -> drawBox(0,60,20,10);
    }else if(vitesse >= 20 && vitesse < 30){
      oled -> drawBox(0,60,30,10);
    }else if(vitesse >= 30 && vitesse < 40){
      oled -> drawBox(0,60,40,10);
    }else if(vitesse >= 40 && vitesse < 50){
      oled -> drawBox(0,60,50,10);
    }else if(vitesse >= 50 && vitesse < 60){
      oled -> drawBox(0,60,60,10);
    }else if(vitesse >= 60 && vitesse < 70){
      oled -> drawBox(0,60,70,10);
    }else if(vitesse >= 70 && vitesse < 80){
      oled -> drawBox(0,60,80,10);
    }else if(vitesse >= 80 && vitesse < 90){
      oled -> drawBox(0,60,90,10);
    }else if(vitesse >= 90){
      oled -> drawBox(0,60,100,10);
    }
  }while (oled -> nextPage());
}

////////////////////// BOUTON POUSSOIR ////////////////////////////////
/*
int IHM :: button_state(){
  int state = digitalRead(PUSHBUTTON);    
}*/

////////////////////// BOUTON POUSSOIR ////////////////////////////////

bool IHM :: button_state(){
  bool state = false;
  if (digitalRead(PUSHBUTTON) == HIGH){
    state = true ;
  }
  //delay(1);
  return state;
}

////////////////// LED qui change avec temperature //////////////////

void IHM :: led_change_couleur(float temp){

  float temperature = temp;

  if( temperature > 0 && temperature < 18){
      allumer_bleu();
  }else if(temperature >= 18 && temperature < 25){
      allumer_orange();
  }else if(temperature >= 25 && temperature < 29){
      allumer_rouge();
  }else if(temperature > 29){
      allumer_rouge_intense();    
  }
}


/////////////  CHOIX DE TEMPERATURE AVEC POTO /////////////////////

float IHM :: choix_temperature(){

  float temp = 20.0;
  float angle = this->poto(); //récupérer valeur potentiomètre
  
  oled -> clearDisplay();  //effacer écran

  while(!this->button_state()){
    angle = this->poto(); 

    oled -> firstPage();
  
    do {
  
      oled -> setFont(u8g2_font_ncenB10_tr);
      oled -> drawStr(0,24,"Choisissez la");
      oled -> drawStr(0,40, "temperature :");
      oled -> drawStr(0,60, String(temp).c_str());
      oled -> drawStr(40,60,"°C ");
      
      if(angle >= 0 && angle < 20){
        temp = 20.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 20 && angle < 40){
        temp = 21.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 40 && angle < 60){
        temp = 22.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 60 && angle < 80){
        temp = 23.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 80 && angle < 100){
        temp = 24.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 100 && angle < 120){
        temp = 25.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 120 && angle < 140){
        temp = 26.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 140 && angle < 160){
        temp = 27.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 160 && angle < 180){
        temp = 28.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 180 && angle < 200){
        temp = 29.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 200 && angle < 220){
        temp = 30.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 220 && angle < 240){
        temp = 31.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 240 && angle < 260){
        temp = 32.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 260 && angle < 280){
        temp = 33.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle >= 280 && angle < 300){
        temp = 34.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }else if(angle = 300){
        temp = 35.0;
        oled -> drawStr(0,60,String(temp).c_str());
      }
    }while (oled -> nextPage());    
  }  
}
