#pragma once

typedef unsigned char  u8;
typedef unsigned int  u32;
typedef unsigned long u64;

typedef float  f32;
typedef double f64;

typedef u8 bool;
#define true 1
#define false 0

typedef struct Length_tracker{
  int token_list_len;
  int token_array_len;
  
} Length_tracker;

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
