#pragma once

#include "mytypes.h"

void read_metadata(PVM * p , IP * code){
  p->pc = code[0].mode;
  p->sp = code[0].code;
  p->sb = code[0].code;
  p->bp = code[0].code;
  p->st = code[0].code + STACK_SIZE;
}

void fetch(PVM * p ,  IP * code){

  p->ip =  code[p->pc];
  p->pc = p->pc + 1;

}

void execute(PVM * p , int * signal){

  if(p->ip.mode == IMPLIED && p->ip.code == HLT){
    *signla = 0;
  }
  
}

void perry(char * src){

  PVM * p = (PVM * )malloc(sizeof(PVM));
  IP * code =  loader(src);

  read_metadata( p , code);

  int signal = 1;

  while(signal){

    fetch( p ,  code );
  
    execute(p , &signal);

  }
  
}
