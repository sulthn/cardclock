#pragma once
#include <Adafruit_GFX.h>

const uint8_t Time_Bitmaps[] PROGMEM = {
  0x74, 0x63, 0x10, 0x46, 0x31, 0x70, 0x00, 0x00, 0x42, 0x10, 0x04, 0x21, 
  0x00, 0x00, 0x70, 0x42, 0x17, 0x42, 0x10, 0x70, 0x00, 0x70, 0x42, 0x17, 
  0x04, 0x21, 0x70, 0x00, 0x04, 0x63, 0x17, 0x04, 0x21, 0x00, 0x00, 0x74, 
  0x21, 0x07, 0x04, 0x21, 0x70, 0x00, 0x74, 0x21, 0x07, 0x46, 0x31, 0x70, 
  0x00, 0x70, 0x42, 0x10, 0x04, 0x21, 0x00, 0x00, 0x74, 0x63, 0x17, 0x46, 
  0x31, 0x70, 0x00, 0x74, 0x63, 0x17, 0x04, 0x21, 0x70, 0x00, 0xD8, 0x00, 
  0x74, 0x63, 0x17, 0x46, 0x31, 0x00, 0x00, 0x04, 0x21, 0x07, 0x46, 0x31, 
  0x70, 0x00, 0x74, 0x21, 0x00, 0x42, 0x10, 0x70, 0x00, 0x00, 0x42, 0x17, 
  0x46, 0x31, 0x70, 0x00, 0x74, 0x21, 0x07, 0x42, 0x10, 0x70, 0x00, 0x74, 
  0x21, 0x07, 0x42, 0x10, 0x00, 0x00, 0x8E, 0xEB, 0x18, 0xC6, 0x31, 0x88, 
  0x00
};

const GFXglyph Time_Glyphs[] PROGMEM = {
  {     0,   5,   9,   7,    1,   -9 },   // 0x30 '0'
  {     7,   5,   9,   7,    1,   -9 },   // 0x31 '1'
  {    14,   5,   9,   7,    1,   -9 },   // 0x32 '2'
  {    21,   5,   9,   7,    1,   -9 },   // 0x33 '3'
  {    28,   5,   9,   7,    1,   -9 },   // 0x34 '4'
  {    35,   5,   9,   7,    1,   -9 },   // 0x35 '5'
  {    42,   5,   9,   7,    1,   -9 },   // 0x36 '6'
  {    49,   5,   9,   7,    1,   -9 },   // 0x37 '7'
  {    56,   5,   9,   7,    1,   -9 },   // 0x38 '8'
  {    63,   5,   9,   7,    1,   -9 },   // 0x39 '9'
  {    70,   1,   5,   7,    3,   -7 },   // 0x3A ':'
  {     0,   0,   0,   0,    0,    0 },   // 0x3B ';'
  {     0,   0,   0,   0,    0,    0 },   // 0x3C '<'
  {     0,   0,   0,   0,    0,    0 },   // 0x3D '='
  {     0,   0,   0,   0,    0,    0 },   // 0x3E '>'
  {     0,   0,   0,   0,    0,    0 },   // 0x3F '?'
  {     0,   0,   0,   0,    0,    0 },   // 0x40 '@'
  {    72,   5,   9,   7,    1,   -9 },   // 0x41 'A'
  {    79,   5,   9,   7,    1,   -9 },   // 0x42 'B'
  {    86,   5,   9,   7,    1,   -9 },   // 0x43 'C'
  {    93,   5,   9,   7,    1,   -9 },   // 0x44 'D'
  {   100,   5,   9,   7,    1,   -9 },   // 0x45 'E'
  {   107,   5,   9,   7,    1,   -9 },   // 0x46 'F'
  {     0,   0,   0,   0,    0,    0 },   // 0x47 'G'
  {     0,   0,   0,   0,    0,    0 },   // 0x48 'H'
  {     0,   0,   0,   0,    0,    0 },   // 0x49 'I'
  {     0,   0,   0,   0,    0,    0 },   // 0x4A 'J'
  {     0,   0,   0,   0,    0,    0 },   // 0x4B 'K'
  {     0,   0,   0,   0,    0,    0 },   // 0x4C 'L'
  {   114,   5,   9,   7,    1,   -9 }    // 0x4D 'M'
};

const GFXfont Time PROGMEM = {(uint8_t *) Time_Bitmaps,     (GFXglyph *)Time_Glyphs, 0x30, 0x4D,   9};