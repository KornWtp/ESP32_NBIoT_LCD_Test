#include <Arduino.h>
#include <CMMC_NB_IoT.h>
#include <U8g2lib.h>
#include <HardwareSerial.h>


#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

CMMC_NB_IoT nb;
CMMC_AT_Bridge &Bridge = nb.Bridge; 


U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 18, /* MOSI=*/ 23, /* MISO=*/ 19);

void setup()
{
  Serial.begin(57600);
  Serial2.begin(9600); 
  u8g2.begin();

  Serial.println("Chiang Mai Maker Club's AT-Bridge engine is started.");
  Bridge.init(&Serial, &Serial2); 
}

void loop()
{
  
  Bridge.loop();
  
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.drawStr(40,10,"KornWtp!!"); 
  u8g2.sendBuffer();          // transfer internal memory to the display
}
