#include "opcodes.h"

void ins_hlt(cpu * c , u32 * code){
  
  // I am just a placeholder ,
  //how do you feel about me wasting memory
  
}


void ins_mov(cpu * c, u32 * code){

  c->gpr[c->ip.part[1]] = code[c->pc];
  c->pc++;
  
}


void ins_movr(cpu * c, u32 * code){

  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[2]];
  
}

void ins_add(cpu * c, u32 * code){

  c->gpr[c->ip.part[1]] = c->gpr[c->ip.part[2]]
    + c->gpr[c->ip.part[3]];
  
}

void ins_debug_print(cpu * c , u32 * code){

  printf("%d\n",c->gpr[c->ip.part[1]]);
  
}

void ins_call(cpu * c , u32 * code){

  c->ret = c->pc + 1;
  c->pc = code[c->pc];
  
}

void ins_ret(cpu * c , u32 * code){

  c->pc = c->ret;
  
}

void ins_cmp(cpu * c , u32 * code){

  if(c->gpr[c->ip.part[1]] == c->gpr[c->ip.part[2]]){
    c->flags = c->flags | 0b01000000;
  }else if(c->gpr[c->ip.part[1]] > c->gpr[c->ip.part[2]]){
    c->flags = c->flags | 0b00100000;
  }else if(c->gpr[c->ip.part[1]] < c->gpr[c->ip.part[2]]){
    c->flags = c->flags | 0b00010000;
  }

}

void ins_je(cpu * c ,  u32 * code){

  if((c->flags & 0b01000000) == 0b01000000){
    c->pc = code[c->pc];
  }
  
}

void ins_jg(cpu * c ,  u32 * code){

  if((c->flags & 0b00100000) == 0b00100000){
    c->pc = code[c->pc];
  }
  
}

void ins_jl(cpu * c ,  u32 * code){

  if((c->flags & 0b00010000) == 0b00010000){
    c->pc = code[c->pc];
  }
  
}


