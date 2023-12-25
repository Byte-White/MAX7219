#include <Arduino.h>
#include "MFont.h"
#ifndef MAX7219_H
#define MAX7219_H


#define OP_DECODEMODE   9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15

class MAX7219
{
  int m_cs,m_clk,m_data;
  unsigned int m_devices; 
  char* dataset;// size = 8 * m_devices
  
  int port_cs,port_clk,port_data;
  volatile uint8_t *out_cs;
  volatile uint8_t *out_clk;
  volatile uint8_t *out_data;
  uint8_t csbit,clkbit,databit;

  MFont* m_font;

  void SPI_send(uint8_t data);

  void send_cmd(uint8_t cmd_byte, uint8_t data_byte,int device=0);  
  void shutDownDevices();
  void turnOnDevices();
  void setupDevices();
  public:
  MAX7219(int cs_pin,int clk_pin,int data_pin,unsigned int devices);
  
  inline unsigned int GetDevicesCount()
  {
    return m_devices;
  }

  void ClearData()
  {
    memset(dataset,0x00,sizeof(dataset[0])*8*m_devices);
  }

  void setFont(MFont* new_font);
  void setIntensity(uint8_t intensity);
  
  void transferData();
  //transfer for 1 device only
  void transferDataForDevice(unsigned int device);

  void setMatrix(int device,char data[8]);
  void setRow(int device, int row, char data);
  void setLed(int x,int y,bool b);
  void setChar(int device,char c);
  void setText(int starting_device,String str);
};
#endif
