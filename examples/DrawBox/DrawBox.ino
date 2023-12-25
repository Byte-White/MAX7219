// Draws a box with an X
#include "MAX7219.h"

#define CS_PIN        10
#define CLK_PIN       11
#define DATA_PIN      12
#define DEVICES_COUNT  1

MAX7219 m(CS_PIN,CLK_PIN,DATA_PIN,DEVICES_COUNT);

char image[] = {0xff,0xc3,0xa5,0x99,0x99,0xa5,0xc3,0xff};

void setup() 
{
  m.setIntensity(0x04);
  m.setMatrix(0,image);
  m.transferData();
}

void loop()
{
  // check documentation for more information
}
