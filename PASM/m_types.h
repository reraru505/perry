#pragma once

typedef unsigned char  u8;
typedef unsigned int  u32;
typedef unsigned long u64;

typedef float  f32;
typedef double f64;

typedef struct label_table{

  char ** label;
  u32 * address;
  int len;
  
}label_table;

typedef struct token{

  char ** tokens;
  int len;
  
}token;


typedef struct raw_code{

  u32 * code;
  int len;
  
}raw_code;


typedef union r32{

  u32   data;
  u8 part[4];
  
} r32;
