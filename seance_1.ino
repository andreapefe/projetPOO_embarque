#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

#include <ChainableLED.h>
 
#define NUM_LEDS 1
 
U8G2_SH1107_SEEED_128X128_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);
ChainableLED leds(3, 5, NUM_LEDS);
 
void setup(void) {
  u8g2.begin();
  leds.init();
  
}

//ceci est le main
void loop(void) {
  leds.setColorRGB(1,0,253,0);
  
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0,24,"PUTAIN LES");
    u8g2.drawStr(0,100,"GARS C LA CANICULE!"); 
  } while ( u8g2.nextPage() );

}
 
