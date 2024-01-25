#pragma once

#define STACK_SIZE 1000000

typedef unsigned char  u8; //sizeof char is 1 bytes = 8 bits
typedef unsigned int  u32; //sizeof int is 4 bytes = 32 bits
typedef unsigned long u64; //sizeof long is 8 bytes = 64 bits

typedef float  f32; //sizeof float is 4 bytes = 32 bits
typedef double f64; //sizeof double is 8 bytes = 64 bits

typedef union r32{

  u32   data;
  u8 part[4];
  
} r32;

typedef struct cpu{

  u32 gpr[8]; //general purpose register array
  f32 fpr[8]; //float point register array 

  u32 tmp; 
  
  u8 flags; // zero | eq | greater | less_than | fuck last 4 bits 
  
  r32 ip;
  u32 pc;

  u32 * stack;
  
  u32 sp;
  u32 bp;

  u8 was_called;
  u32 ret;
  
} cpu;

typedef struct code_and_len{

  u32 * src;
  int len;
  
}code_and_len;
