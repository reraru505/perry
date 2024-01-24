#pragma once

#define STACK_SIZE 1000000

typedef unsigned char  u8; //sizeof char is 1 bytes = 8 bits
typedef unsigned int  u32;//sizeof int is 4 bytes = 32 bits
typedef unsigned long u64;//sizeof long is 8 bytes = 64 bits

typedef float  f32;//sizeof float is 4 bytes = 32 bits
typedef double f64;//sizeof double is 8 bytes = 64 bits

typedef union r32{

  u32   data;//holds 32 bit of data

  u8 part[4];//part[0]=8 bits to hold the operations
            //part[1]=8 bits to hold the source
            //part[2]=8 bits to hold the Destination
            //part[3]=8 bits to hold other information as per the instruction
/* The destination and the source may vary as per the operations we perform
    So to prevent running out of space and ambiguity */
  
} r32;

typedef struct cpu{

  u32 gpr[8];//general purpose register
  f32 fpr[8];//float point register
  
  r32 ip;//instruction pointer
  u32 pc;//program counter

  u32 * stack;
  
  u32 sp;//stack pointer
  u32 bp;//base (of the stack) pointer

  u32 ret;//return address register
  
} cpu;
