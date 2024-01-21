#pragma once

typedef unsigned char  u8;
typedef unsigned int  u32;
typedef unsigned long u64;

typedef float  f32;
typedef double f64;

//typedef struct token {
//
//  char ** tokens;
//  
//  
//} token;

typedef union r32{

  u32   data;
  u8 part[4];
  
} r32;
