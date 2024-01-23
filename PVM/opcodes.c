#include "opcodes.h"

void ins_hlt(cpu * c , u32 * code){
  
  exit(0);
  
}


void ins_mov(cpu * c, u32 * code){

  c->gpr[c->ip.part[1]] = code[c->pc];
  c->pc++;
  
}


void ins_movr(cpu * c, u32 * code){

  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[2]];
  
}

void ins_add(cpu * c, u32 * code){

  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[2]] + c->gpr[c->ip.part[3]];
  
}

void ins_debug_print(cpu * c , u32 * code){

  printf("%d\n",c->gpr[c->ip.part[1]]);
  
}
