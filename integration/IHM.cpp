#include "IHM.h"

IHM::IHM(){
  rgb = new ChainableLED(PIN_CLK,DATA_PIN,NUMBER_OF_LEDS);
  oled = new U8G2_SH1107_SEEED_128X128_1_SW_I2C(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
}

IHM :: ~IHM(){}

void IHM :: init_IHM(){
  rgb->init();
  oled -> begin();
  Serial.begin(9600);
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
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
  rgb->setColorHSL(0,15,20,50);
  rgb->setColorRGB(0,255,140,0);
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

void IHM :: change_color(float temp){   //à tester avec le cpateur
  if(temp >= 20 && temp < 22){
    this -> allumer_bleu();
  }else if(temp >= 22 && temp < 24){
    this -> allumer_orange();
  }else if(temp >= 24){
    this -> allumer_rouge();
  }
}


////////////////////// OLED ////////////////////////////////

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

void IHM :: underline(int mode){

  oled -> firstPage();
  do {
    oled -> setFont(u8g2_font_ncenB10_tr);
    if(mode == 1){
      oled -> drawHLine(0,51,100);
    }else{
    oled -> drawVLine(50,51,100);
    }
  } while (oled -> nextPage());
}


////////////////////// POTO ////////////////////////////////

float IHM :: poto(){
  
  float voltage;
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  voltage = (float)sensor_value*ADC_REF/1023;
  float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;
 // Serial.println("The angle between the mark and the starting position:");
 // Serial.println(degrees);

  return degrees;
}


////////////////////// POTO + OLED ////////////////////////////////

mode_utilisation IHM :: config_mode(){
   //oled -> clearDisplay();  //effacer écran
   
    float angle = this -> poto(); //récupérer valeur potentiomètre
    oled -> firstPage();
    do {
    oled -> setFont(u8g2_font_ncenB10_tr);
    oled -> drawStr(10,25,"Automatique");
    oled -> drawStr(10,80,"Manuel");
    if(angle < 150){                //en haut
      oled -> drawHLine(10,26,100);
    }else{                          //en bas
    oled -> drawHLine(10,81,55);
    }
  } while (oled -> nextPage());
}