#pragma once

#define STACK_SIZE 1000000

typedef unsigned char  u8;
typedef unsigned int  u32;
typedef unsigned long u64;

typedef float  f32;
typedef double f64;

typedef union r32{

  u32   data;
  u8 part[4];
  
} r32;

typedef struct cpu{

  u32 gpr[8];
  f32 fpr[8];
  
  r32 ip;
  u32 pc;

  u32 * stack;
  
  u32 sp;
  u32 bp;

  u32 ret;
  
} cpu;

