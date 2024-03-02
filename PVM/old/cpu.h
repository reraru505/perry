#pragma once


typedef enum AM{ //addressing mode

  NIL,
  RTR,
  RTM,
  RTA,
  MTR,
  MTM,
  MTA,
  ATR,
  ATM,
  ATA
  
}AM;

typedef struct cpu{

  u32 gpr[8]; //general purpose register array
  f32 fpr[8]; //float point register array 

  u32 tmp; 
  
  u8 flags; // not eq | eq | greater | less_than | fuck last 4 bits 
  
  r32 ip;
  u32 pc;

  u32 * stack;
  
  u32 sp;
  u32 bp;

  u8 was_called;
  u32 ret;

  
  
} cpu;

