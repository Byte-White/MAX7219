// Displays texts on the screen
#include "MAX7219.h"

#define CS_PIN        10
#define CLK_PIN       11
#define DATA_PIN      12
#define DEVICES_COUNT  8

MAX7219 m(CS_PIN,CLK_PIN,DATA_PIN,DEVICES_COUNT);

void setup() 
{
  m.setIntensity(0x04);
}

void loop()
{
  // check documentation for more information
  m.ClearData();
  m.setText(0,"HOW R U?");
  m.transferData();
  delay(1500);
  m.ClearData();
  m.setText(0,"GOOD!");
  m.transferData();
  delay(1000);
  m.ClearData();
  m.setText(0,"AND U?");
  m.transferData();
  delay(500);
  m.ClearData();
  m.setText(0,"PERFECT.");
  m.transferData();
  delay(500);
}
