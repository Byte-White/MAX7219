#ifndef MFONT_H
#define MFONT_H
class MFont
{
  public:
  MFont()
  {

  }
  // should return 8 bytes
  // 94 printable characters
  virtual char* getMatrix(char symbol)
  {
    #ifndef NO_DEFAULT_FONT
    static char charmap[][8] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // Space
    {0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x08, 0x00},  // !
    {0x36, 0x36, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00},  // "
    {0x00, 0x14, 0x3E, 0x14, 0x14, 0x3E, 0x14, 0x00},  // #
    {0x08, 0x1C, 0x28, 0x1C, 0x0A, 0x3C, 0x08, 0x00},  // $
    {0x00, 0x00, 0x32, 0x34, 0x08, 0x16, 0x26, 0x00},  // %
    {0x00, 0x0C, 0x12, 0x0C, 0x34, 0x2E, 0x3C, 0x00},  // &
    {0x0C, 0x0C, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00},  // '
    {0x18, 0x24, 0x24, 0x18, 0x24, 0x24, 0x18, 0x00},  // (
    {0x18, 0x24, 0x24, 0x18, 0x24, 0x24, 0x18, 0x00},  // )
    {0x00, 0x00, 0x14, 0x08, 0x3E, 0x08, 0x14, 0x00},  // *
    {0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 0x00},  // +
    {0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x04, 0x08},  // ,
    {0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00},  // -
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00},  // .
    {0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x00},  // /
    {0x1C, 0x22, 0x26, 0x2A, 0x32, 0x22, 0x1C, 0x00},  // 0
    {0x08, 0x18, 0x08, 0x08, 0x08, 0x08, 0x1C, 0x00},  // 1
    {0x1C, 0x22, 0x02, 0x0C, 0x10, 0x20, 0x3E, 0x00},  // 2
    {0x1C, 0x22, 0x02, 0x0C, 0x02, 0x22, 0x1C, 0x00},  // 3
    {0x0C, 0x14, 0x24, 0x3E, 0x04, 0x04, 0x04, 0x00},  // 4
    {0x3E, 0x20, 0x20, 0x3C, 0x02, 0x22, 0x1C, 0x00},  // 5
    {0x1C, 0x22, 0x20, 0x3C, 0x22, 0x22, 0x1C, 0x00},  // 6
    {0x3E, 0x02, 0x04, 0x08, 0x10, 0x10, 0x10, 0x00},  // 7
    {0x1C, 0x22, 0x22, 0x1C, 0x22, 0x22, 0x1C, 0x00},  // 8
    {0x1C, 0x22, 0x22, 0x1E, 0x02, 0x02, 0x1C, 0x00},  // 9
    {0x00, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x00},  // :
    {0x00, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x04, 0x08},  // ;
    {0x00, 0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02},  // <
    {0x00, 0x00, 0x3E, 0x00, 0x3E, 0x00, 0x00, 0x00},  // =
    {0x00, 0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08},  // >
    {0x1C, 0x22, 0x02, 0x0C, 0x10, 0x00, 0x10, 0x00},  // ?
    {0x1C, 0x22, 0x02, 0x1A, 0x2A, 0x2E, 0x10, 0x0E},  // @
    {0x08, 0x14, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x00},  // A
    {0x3C, 0x22, 0x22, 0x3C, 0x22, 0x22, 0x3C, 0x00},  // B
    {0x1E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x1E, 0x00},  // C
    {0x3C, 0x22, 0x22, 0x22, 0x22, 0x22, 0x3C, 0x00},  // D
    {0x3E, 0x20, 0x20, 0x3C, 0x20, 0x20, 0x3E, 0x00},  // E
    {0x3E, 0x20, 0x20, 0x3C, 0x20, 0x20, 0x20, 0x00},  // F
    {0x1E, 0x20, 0x20, 0x2E, 0x22, 0x22, 0x1E, 0x00},  // G
    {0x22, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x22, 0x00},  // H
    {0x1C, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1C, 0x00},  // I
    {0x0E, 0x04, 0x04, 0x04, 0x04, 0x24, 0x18, 0x00},  // J
    {0x22, 0x24, 0x28, 0x38, 0x28, 0x24, 0x22, 0x00},  // K
    {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3E, 0x00},  // L
    {0x22, 0x36, 0x2A, 0x22, 0x22, 0x22, 0x22, 0x00},  // M
    {0x22, 0x22, 0x32, 0x2A, 0x26, 0x22, 0x22, 0x00},  // N
    {0x1C, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x00},  // O
    {0x3C, 0x22, 0x22, 0x3C, 0x20, 0x20, 0x20, 0x00},  // P
    {0x1E, 0x22, 0x22, 0x22, 0x2A, 0x24, 0x1A, 0x00},  // Q
    {0x3C, 0x22, 0x22, 0x3C, 0x28, 0x24, 0x22, 0x00},  // R
    {0x1E, 0x20, 0x20, 0x1C, 0x02, 0x02, 0x3C, 0x00},  // S
    {0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00},  // T
    {0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x00},  // U
    {0x22, 0x22, 0x22, 0x22, 0x22, 0x14, 0x08, 0x00},  // V
    {0x22, 0x22, 0x22, 0x22, 0x2A, 0x36, 0x22, 0x00},  // W
    {0x22, 0x22, 0x14, 0x08, 0x14, 0x22, 0x22, 0x00},  // X
    {0x22, 0x22, 0x22, 0x1C, 0x08, 0x08, 0x08, 0x00},  // Y
    {0x3E, 0x02, 0x04, 0x08, 0x10, 0x20, 0x3E, 0x00}   // Z
  };
  
    return charmap[(int)symbol-(int)(' ')];
  #else
  return 0;
  #endif
  }
};
#endif