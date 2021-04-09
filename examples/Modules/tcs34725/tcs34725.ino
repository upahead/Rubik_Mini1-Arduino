#include "tcs34725_driver.h"
#include <Wire.h>





void setup(void) {
  Serial.begin(115200);
  Wire.begin();
}

void loop(void) {
  uint16_t r, g, b, c;
  TCS34725 tcs = TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);      
  tcs.begin();                                                                                      //Initialize tcs34725
  tcs.getRawData(&r, &g, &b, &c);                                                                   //Get red, green, blue and transparent channel data
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");                                   
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
}
