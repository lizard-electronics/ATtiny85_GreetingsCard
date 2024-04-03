#ifndef _STYLES_H_
#define _STYLES_H_

#include <Arduino.h>

#define N_STYLES 2

#define SNOWFLAKE1_W_H 1
const uint8_t snowflake1_bmp[] PROGMEM = {0x01};

#define SNOWFLAKE2_W_H 9
const uint8_t snowflake2_bmp[] PROGMEM =
// ................ 0   1 Page 0
// ....#........... 1   2
// ....#........... 2   4
// ...###.......... 3   8
// .#######........ 4  16
// ...###.......... 5  32
// ....#........... 6  64
// ....#........... 7 128
// ................ 0   1 Page 1
{
  0x00, 0x10, 0x10, 0x38, 0xFE, 0x38, 0x10, 0x10, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// [NOT USED, due to memory limitations]
/* #define SNOWFLAKE3_W_H 9
const uint8_t snowflake3_bmp[] PROGMEM =
// ...#.#.......... 0   1 Page 0
// .#..#..#........ 1   2
// ..#.#.#......... 2   4
// #..###..#....... 3   8
// .#######........ 4  16
// #..###..#....... 5  32
// ..#.#.#......... 6  64
// .#..#..#........ 7 128
// ...#.#.......... 0   1 Page 1
{
  0x28, 0x92, 0x54, 0x39, 0xFE, 0x39, 0x54, 0x92, 0x28,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00
}; */

#endif