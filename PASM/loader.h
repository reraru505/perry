#pragma once
#include "assert.h"
#include "m_types.h"
#include "stdio.h"
#include "stdlib.h"

//Takes in assembly src

char * loader(char * src){
  
  FILE * fp = fopen(src,"r");
  assert(fp != NULL);
  
  fseek(fp , 0 , SEEK_END);

  u64 f_len = ftell(fp);

  rewind(fp);

  u8 * buffer = (u8 *) calloc(f_len , sizeof(u8));

  for(int i = 0 ; i  < (f_len -1) ;i++){
    buffer[i] = getc(fp); 
  }
  
  fclose(fp);

  return buffer;
}
