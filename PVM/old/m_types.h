#pragma once

#define STACK_SIZE 1000000

typedef unsigned char  u8; //sizeof char is 1 bytes = 8 bits
typedef unsigned int  u32; //sizeof int is 4 bytes = 32 bits
typedef unsigned long u64; //sizeof long is 8 bytes = 64 bits

typedef float  f32; //sizeof float is 4 bytes = 32 bits
typedef double f64; //sizeof double is 8 bytes = 64 bits


typedef struct IP{

  u32 OPC : 4; // optional operand 3
  u32 OPB : 4; // optional operand 2
  u32 OPA : 4; // optional operand 1
  u32 OPO : 16; // opcode
  u32 ADM : 4; // addressing mode 
}IP;


typedef union r32{

  u32   data;
  IP      ip;
  u8 part[4];
  
} r32;

typedef struct len_tracker{

  int code_len;
  
} len_tracker;

typedef struct code_and_len{

  u32 * src;
  int len;
  
}code_and_len;
