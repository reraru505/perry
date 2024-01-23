#pragma once
#include <string.h>
#include "opcodes.h"
#include "m_types.h"

typedef struct raw_code{

  u32 * code;
  int len;
  
}raw_code;


raw_code opcode_selector(char ** tokens , int len){

  int is_data_next = 0;

  u32 * buffer  =  (u32 *) calloc(1000 , sizeof(u32));
  int buff_index = 0;
  
  r32 ip;

  printf("len = %d \n ",len);
  
  for (int i = 0 ; i < len;i++){

    if(!strcmp(tokens[i],"HLT")){
      ip = is_hlt(tokens , &i , &is_data_next);
    }else if(is_data_next == 1){
      ip = is_data(tokens , &i , &is_data_next);
    }else if(!strcmp(tokens[i],"MOV")){
      ip = is_mov(tokens , &i , &is_data_next);
    }else if(!strcmp(tokens[i],"ADD")){
      ip = is_add(tokens , &i , &is_data_next);
    }else if(!strcmp(tokens[i],"PRINT")){
      ip = is_print(tokens , &i , &is_data_next);
    }
    buffer[buff_index] = ip.data;
    buff_index++;
  }
  
  u32 * new_ret = (u32 *) calloc(buff_index ,sizeof(u32));
  for(int  i = 0 ; i < buff_index ;i++){
    new_ret[i] = buffer[i];
  }

  free(buffer);

  raw_code retval;

  retval.code =  new_ret;
  retval.len = buff_index;

  return retval;
  
 
}
