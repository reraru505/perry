#include "fetch.h"
#include "stdlib.h"

void init_cpu(cpu * c){

  c = (cpu *) malloc(sizeof(cpu));
  
  c->pc = 0;

  c->stack = (u32 *) calloc(STACK_SIZE , sizeof(u32));

  c->sp = 0;
  c->bp = 0;

  c->ret = 0;
  
}

void fetch(cpu * c , u32 * code){

  c->ip.data = code[c->pc];
  c->pc++;
  
}
