#include "fetch.h"
#include "stdlib.h"
#include "stdio.h"

void init_cpu(cpu * c , u32 * code , int len){

  c->was_called = 0;
  c-> flags = 0;
  
  c->pc = code[len-1];
  printf("yo ho : %d\n\n\n",c->pc);
  
  c->stack = (u32 *) calloc(STACK_SIZE , sizeof(u32));

  c->sp = 0;
  c->bp = 0;

  c->ret = 0;
  
}

void fetch(cpu * c , u32 * code){

  c->ip.data = code[c->pc];
  c->pc++;
  
}
