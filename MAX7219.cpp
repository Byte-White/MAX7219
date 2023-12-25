#include"MAX7219.h"

void MAX7219::SPI_send(uint8_t data)
  {
    for(uint8_t i=0; i<8; i++)
    {
        *out_clk &= ~clkbit;//digitalWrite(m_clk, LOW);                  //CLK low pulse
        //----------------------------------------------------------
        if(data & 0x80) *out_data |= databit;//digitalWrite(m_data, HIGH); //o/p high if MSB = 1
        else *out_data &= ~databit;//digitalWrite(m_data, LOW);             //o/p low if MSB = 0
        //----------------------------------------------------------
        data = data << 1;                         //shift data left one bit
        *out_clk |= clkbit;//digitalWrite(m_clk, HIGH);                 //CLK high pulse
    }
  }

  void MAX7219::send_cmd(uint8_t cmd_byte, uint8_t data_byte,int device)
  {
    *out_cs &= ~csbit;//digitalWrite(m_cs, LOW);   //CS low pulse to enable MAX7219   
    //---------------------------------------------------------
    SPI_send(cmd_byte);       //send command byte to MAX7219
    SPI_send(data_byte);      //send data byte to MAX7219
    for(int k = 0;k<device;k++)
    {
      SPI_send(0x00);
      SPI_send(0x00);
    }//selects a device
    //----------------------------------------------------------
    *out_cs |= csbit;//digitalWrite(m_cs, HIGH);  //CS high pulse to disable MAX7219    
  }
  
  void MAX7219::shutDownDevices()
  {
    for(int i = 0; i<m_devices ; i++)
      send_cmd(OP_SHUTDOWN, 0x00,i);
  }
  void MAX7219::turnOnDevices()
  {
    for(int i = 0; i<m_devices ; i++)
      send_cmd(OP_SHUTDOWN, 0x01,i);
  }
  
  void MAX7219::setupDevices()
  {
    shutDownDevices();

    for(int i = 0; i <m_devices;i++)
    {
      send_cmd(OP_SHUTDOWN, 0x01,i);          //turn ON MAX7219
      send_cmd(OP_DISPLAYTEST, 0x00,i);       //turn off display test
      send_cmd(OP_DECODEMODE, 0x00,i);          //decoding mode OFF
      send_cmd(OP_INTENSITY, 0x01,i);       //light intensity (0-15)
      send_cmd(OP_SCANLIMIT, 0x07,i);          //scan limit: all digits ON
    }
  }


  MAX7219::MAX7219(int cs_pin,int clk_pin,int data_pin,unsigned int devices)
  {
    m_cs      = cs_pin;
    m_clk     = clk_pin;
    m_data    = data_pin;
    m_devices = devices;
    dataset = (char*)malloc(8 * m_devices);
    
    pinMode(m_cs, OUTPUT);  
    pinMode(m_clk, OUTPUT); 
    pinMode(m_data, OUTPUT);
    digitalWrite(m_cs, HIGH);
    digitalWrite(m_clk, LOW);

  //set up ports,bits,etc
    port_cs = digitalPinToPort(cs_pin);
    port_clk = digitalPinToPort(clk_pin);
    port_data = digitalPinToPort(data_pin);

    out_cs = portOutputRegister(port_cs); 
    out_clk = portOutputRegister(port_clk); 
    out_data = portOutputRegister(port_data); 
    
    csbit = digitalPinToBitMask(cs_pin);
    clkbit = digitalPinToBitMask(clk_pin);
    databit = digitalPinToBitMask(data_pin);
    
    ClearData();
        
    m_font = new MFont();

    setupDevices();
    transferData(); // clears the display
  }
  void MAX7219::setFont(MFont* new_font)
  {
    if(m_font!=nullptr)delete m_font;
    m_font = new_font;
  }

  void MAX7219::setIntensity(uint8_t intensity)
  {
    for(int i = 0; i <m_devices;i++)
      send_cmd(0x0A,intensity,i);
  }
  
  void MAX7219::transferData()
  {
    for(int i = 0; i <m_devices;i++)
      transferDataForDevice(i); // transfers data for a single device
  }

  //transfer for 1 device only
  void MAX7219::transferDataForDevice(unsigned int device)
  {
    for(int j = 0; j<8;j++)
    {      
      *out_cs &= ~csbit;
      SPI_send(j+1);//address
      SPI_send(dataset[device*8 + j]);//data 
      for(int k = 0;k<device;k++)//selects a device
      { 
        SPI_send(0x00);
        SPI_send(0x00);
      }
      //send_cmd(OP_NOOP,0x00); 
      *out_cs |= csbit;
    }
  }
  void MAX7219::setMatrix(int device,char data[8])
  {
    memcpy(dataset + (device * 8), data, 8);
  }

  void MAX7219::setRow(int device, int row, char data)
  {
    dataset[(device*8) + row] = data;
  }

  void MAX7219::setLed(int x,int y,bool b)
  {
    if(b == 1)
    dataset[y+((x/8)*8)] |= b<<(x%8);
    else
    dataset[y+((x/8)*8)] &= ~(b<<(x%8));
  }

  void MAX7219::setChar(int device,char c)
  {//21-7E / from ! to ~ (all printable characters)
    setMatrix(device,m_font->getMatrix(c));
  }
  void MAX7219::setText(int starting_device,String str)
  {
    for(int i = 0;i<str.length();i++)
    {
      setChar(m_devices-starting_device-i-1,str[i]);
    }
  }