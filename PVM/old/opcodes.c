#include "opcodes.h"
#include "stdio.h"

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

  c->ret = c->pc+1;
  c->was_called = 1;
  c->pc = code[c->pc];
}

void ins_ret(cpu * c , u32 * code){
  
  if(c->was_called == 1){
    c->pc = c->ret;
    c->was_called = 0;
  }
  
}

void ins_cmp(cpu * c , u32 * code){

  c->flags = 0;
  
  if(c->gpr[c->ip.part[1]] == c->gpr[c->ip.part[2]]){
    c->flags = c->flags | 0b01000000;
  }
  if(c->gpr[c->ip.part[1]] != c->gpr[c->ip.part[2]]){
    c->flags = c->flags | 0b10000000;
  }
  if(c->gpr[c->ip.part[1]] > c->gpr[c->ip.part[2]]){
    c->flags = c->flags | 0b00100000;
  }
  if(c->gpr[c->ip.part[1]] < c->gpr[c->ip.part[2]]){
    c->flags = c->flags | 0b00010000;
  }

}

void ins_je(cpu * c ,  u32 * code){

  if((c->flags & 0b01000000) == 64){
    c->ret = c->pc+1;
    c->was_called = 1;
    c->pc = code[c->pc];
  }else{
    c->pc++;
  }
  
}


void ins_jne(cpu * c ,  u32 * code){

  if((c->flags & 0b10000000) == 128){
    c->ret = c->pc+1;
    c->was_called = 1;
    c->pc = code[c->pc];
  }else{
    c->pc++;
  }
  
}


void ins_jg(cpu * c ,  u32 * code){

  if((c->flags & 0b00100000) == 32){
    c->ret = c->pc+1;
    c->was_called = 1;
    c->pc = code[c->pc];
  }else{
    c->pc++;
  }
  
}

void ins_jl(cpu * c ,  u32 * code){

  if((c->flags & 0b00010000) == 16){
    c->ret = c->pc + 1;
    c->was_called = 1;
    c->pc = code[c->pc];
  }else{
    c->pc++;
  }
  
}


void ins_label(cpu * c ,  u32 * code){
  //empty ( o W o )
}
