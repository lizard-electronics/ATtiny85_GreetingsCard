#ifndef BITMAPS_H
#define BITMAPS_H

#include "OLED_Display.h"

// Christmas Tree Logo
#define XMASTREE_LOGO_BMPWIDTH  32
#define XMASTREE_LOGO_BMPHEIGHT 32
const unsigned char XmasTree_Logo[] PROGMEM = {
  B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,B00000000,
  B00000000,B00000001,B10000000,B00000000,
  B00000000,B00000001,B10000000,B00000000,
  B00000000,B00000011,B11000000,B00000000,
  B00000000,B00000011,B11100000,B00000000,
  B00000000,B00000111,B11100000,B00000000,
  B00000000,B00001110,B11110000,B00000000,
  B00000000,B00011111,B11111000,B00000000,
  B00000000,B00111111,B11011100,B00000000,
  B00000000,B01111111,B00111110,B00000000,
  B00000000,B01101100,B11110110,B00000000,
  B00000000,B00001111,B11110000,B00000000,
  B00000000,B00011011,B11111000,B00000000,
  B00000000,B00111011,B11011100,B00000000,
  B00000000,B01111101,B11111110,B00000000,
  B00000000,B11111110,B11111111,B00000000,
  B00000000,B00011111,B00111000,B00000000,
  B00000000,B00011011,B10011000,B00000000,
  B00000000,B00111111,B11101100,B00000000,
  B00000000,B01111111,B11100110,B00000000,
  B00000000,B01100000,B00001110,B00000000,
  B00000000,B11111000,B11111111,B00000000,
  B00000001,B11111111,B11111111,B10000000,
  B00000011,B11111111,B11111111,B11000000,
  B00000000,B00000011,B11000000,B00000000,
  B00000000,B00000011,B11000000,B00000000,
  B00000000,B00000011,B11000000,B00000000,
  B00000000,B00000011,B11000000,B00000000,
  B00000000,B00000011,B11000000,B00000000,
  B00000000,B00000011,B10000000,B00000000,
  B00000000,B00000000,B00000000,B00000000
};

// Snow Flakes: Animation Idle
const unsigned char SnowFlake_AnimationIdle [] PROGMEM = {
  0x0F, 0x0A, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xB1, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x44, 0x40, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xB1, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x81, 0x40, 0x00, 0x00, 0x00,
  0x0F, 0x0A, 0x1E, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x01, 0x41, 0x05, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x0A, 0x18, 0x00, 0x00, 0xA8, 0x00, 0x01, 0x00, 0x07, 0x41, 0x05, 0xC0, 0x00, 0x02, 0x00,
  0x1D, 0x04, 0x17, 0x00, 0x01, 0xAC, 0x00, 0x04, 0x40, 0x00, 0xC2, 0x86, 0x00, 0x00, 0x08, 0x80,
  0x05, 0x04, 0x14, 0x00, 0x00, 0x70, 0x00, 0x01, 0x00, 0x03, 0xC2, 0x87, 0x80, 0x00, 0x02, 0x00,
  0x14, 0x0E, 0x05, 0x00, 0x01, 0xAC, 0x00, 0x04, 0x40, 0x00, 0x2C, 0x68, 0x00, 0x00, 0x08, 0x80,
  0x00, 0x15, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x01, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x02, 0x00,
  0x00, 0x24, 0x80, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x68, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC2, 0x87, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x11, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0xC2, 0x86, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x41, 0x05, 0xC0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x41, 0x05, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x81, 0x40, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x40, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0x44, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x28, 0x1C, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x50, 0x00,
  0x22, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x08, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x58, 0x00,
  0x08, 0x00, 0x08, 0x00, 0x00, 0x3A, 0x08, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x14, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x58, 0x00,
  0x00, 0x00, 0x88, 0x80, 0x00, 0x1E, 0x14, 0x3C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x50, 0x00,
  0x00, 0x00, 0x2A, 0x00, 0x00, 0x01, 0x63, 0x40, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x44, 0x00,
  0x00, 0x00, 0x6B, 0x00, 0x00, 0x00, 0x88, 0x80, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x01, 0x63, 0x40, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x6B, 0x00, 0x00, 0x1E, 0x14, 0x3C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x2A, 0x00, 0x00, 0x06, 0x14, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x88, 0x80, 0x00, 0x3A, 0x08, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Snow Flakes: Animation 1
const unsigned char SnowFlake_Animation1 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x14, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x44, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x3A, 0x08, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x11, 0x00, 0x00, 0x00, 0x0A, 0x08, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00,
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x28, 0x1C, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x24, 0x80, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x14, 0x0E, 0x05, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x04, 0x14, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1D, 0x04, 0x17, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x0A, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0x0A, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xB1, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x44, 0x40, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xB1, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x81, 0x40, 0x00, 0x00, 0x00,
  0x0F, 0x0A, 0x1E, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x01, 0x41, 0x05, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x0A, 0x18, 0x00, 0x00, 0xA8, 0x00, 0x01, 0x00, 0x07, 0x41, 0x05, 0xC0, 0x00, 0x02, 0x00,
  0x1D, 0x04, 0x17, 0x00, 0x01, 0xAC, 0x00, 0x04, 0x40, 0x00, 0xC2, 0x86, 0x00, 0x00, 0x08, 0x80,
  0x05, 0x04, 0x14, 0x00, 0x00, 0x70, 0x00, 0x01, 0x00, 0x03, 0xC2, 0x87, 0x80, 0x00, 0x02, 0x00,
  0x14, 0x0E, 0x05, 0x00, 0x01, 0xAC, 0x00, 0x04, 0x40, 0x00, 0x2C, 0x68, 0x00, 0x00, 0x08, 0x80,
  0x00, 0x15, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x01, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x02, 0x00,
  0x00, 0x24, 0x80, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x68, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC2, 0x87, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x11, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0xC2, 0x86, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x41, 0x05, 0xC0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x41, 0x05, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x81, 0x40, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x40, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0x44, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x28, 0x1C, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x50, 0x00
};

// Snow Flakes: Animation 2
const unsigned char SnowFlake_Animation2 [] PROGMEM = {
  0x22, 0x00, 0x6B, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0x44, 0x00,
  0x08, 0x00, 0x1C, 0x00, 0x00, 0x28, 0x1C, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x50, 0x00,
  0x22, 0x00, 0x6B, 0x00, 0x00, 0x0A, 0x08, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x58, 0x00,
  0x08, 0x00, 0x2A, 0x00, 0x00, 0x3A, 0x08, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00,
  0x00, 0x00, 0x88, 0x80, 0x00, 0x06, 0x14, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x58, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x14, 0x3C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x50, 0x00,
  0x00, 0x00, 0x08, 0x00, 0x00, 0x01, 0x63, 0x40, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x44, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x80, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x63, 0x40, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x14, 0x3C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x14, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x3A, 0x08, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x11, 0x00, 0x00, 0x00, 0x0A, 0x08, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x28, 0x1C, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x24, 0x80, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x14, 0x0E, 0x05, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x04, 0x14, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1D, 0x04, 0x17, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x0A, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0x0A, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xB1, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x44, 0x40, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xB1, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x81, 0x40, 0x00, 0x00, 0x00,
  0x0F, 0x0A, 0x1E, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x01, 0x41, 0x05, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x0A, 0x18, 0x00, 0x00, 0xA8, 0x00, 0x01, 0x00, 0x07, 0x41, 0x05, 0xC0, 0x00, 0x02, 0x00,
  0x1D, 0x04, 0x17, 0x00, 0x01, 0xAC, 0x00, 0x04, 0x40, 0x00, 0xC2, 0x86, 0x00, 0x00, 0x08, 0x80,
  0x05, 0x04, 0x14, 0x00, 0x00, 0x70, 0x00, 0x01, 0x00, 0x03, 0xC2, 0x87, 0x80, 0x00, 0x02, 0x00,
  0x14, 0x0E, 0x05, 0x00, 0x01, 0xAC, 0x00, 0x04, 0x40, 0x00, 0x2C, 0x68, 0x00, 0x00, 0x08, 0x80,
  0x00, 0x15, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x01, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x02, 0x00,
  0x00, 0x24, 0x80, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x68, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC2, 0x87, 0x80, 0x00, 0x00, 0x00
};

// Snow Flakes: Animation 3
const unsigned char SnowFlake_Animation3 [] PROGMEM = {
  0x00, 0x24, 0x80, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x00, 0x2C, 0x68, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC2, 0x87, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x11, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0xC2, 0x86, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x41, 0x05, 0xC0, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x41, 0x05, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x81, 0x40, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x40, 0x00,
  0x22, 0x00, 0x08, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0x44, 0x00,
  0x00, 0x00, 0x88, 0x80, 0x00, 0x28, 0x1C, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x50, 0x00,
  0x00, 0x00, 0x2A, 0x00, 0x00, 0x0A, 0x08, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x58, 0x00,
  0x00, 0x00, 0x6B, 0x00, 0x00, 0x3A, 0x08, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00,
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x06, 0x14, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x58, 0x00,
  0x00, 0x00, 0x6B, 0x00, 0x00, 0x1E, 0x14, 0x3C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x50, 0x00,
  0x00, 0x00, 0x2A, 0x00, 0x00, 0x01, 0x63, 0x40, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x44, 0x00,
  0x00, 0x00, 0x88, 0x80, 0x00, 0x00, 0x88, 0x80, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x63, 0x40, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00,
  0x00, 0x00, 0x08, 0x00, 0x00, 0x1E, 0x14, 0x3C, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x14, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x3A, 0x08, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x11, 0x00, 0x00, 0x00, 0x0A, 0x08, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x28, 0x1C, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x24, 0x80, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x14, 0x0E, 0x05, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x05, 0x04, 0x14, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1D, 0x04, 0x17, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x0A, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00,
  0x0F, 0x0A, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xB1, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 0x00
};

#endif