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

  //this is a temperory solution so
  //suck it up if you have suggestions for now
  
  u32 * buffer  =  (u32 *) calloc(32 * 1000 * 1000 ,
				  sizeof(u32));

  u32 buff_index = 0;
  
  r32 ip;

  label_table labels;
  
  for (int i = 0 ; i < len ; i++){
    printf("%s\n",tokens[i]);
  }
  
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
      
    }else if (tokens[i][0] == '_'){
      //ip = is_label(tokens , &i , &is_data_next);
      
    }else if(!strcmp(tokens[i],"CALL")){
      ip = is_call(tokens , &i , &is_data_next);
      
    }else if(!strcmp(tokens[i],"RET")){
      ip = is_ret(tokens , &i , &is_data_next);
      
    }else if(!strcmp(tokens[i],"JE")){
      ip = is_je(tokens , &i , &is_data_next);
      
    }else if(!strcmp(tokens[i],"JG")){
      ip = is_jg(tokens , &i , &is_data_next);
      
    }else if(!strcmp(tokens[i],"JL")){
      ip = is_jl(tokens , &i , &is_data_next);
      
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
