#pragma once
#include <string.h>
#include "opcodes.h"
#include "m_types.h"


raw_code opcode_selector(char ** tokens , int len){

  int is_data_next = 0;
  int is_address_next = 0;
  
  //this is a temperory solution so
  //suck it up if you have suggestions for now
  
  u32 * buffer  =  (u32 *) calloc(32 * 1000 * 1000 ,
				  sizeof(u32));

  //as mentioned this is also a temperory solution
  label_table * lt = (label_table *) malloc(sizeof(label_table));
  lt->label = (char **) calloc(1000,sizeof(char*));  
  lt->address = (u32 *) calloc(1000,sizeof(u32));

  u32 buff_index = 0;
  
  r32 ip;

  label_table labels;

  printf("len : %d\n",len);
  
  for (int i = 0 ; i < len ; i++){
    printf("%s\n",tokens[i]);
  }

  
  
  for (int i = 0 ; i < len;i++){

    if(!strcmp(tokens[i],"HLT")){
      ip = is_hlt(tokens , &i , &is_data_next);
      
    }else if(is_data_next == 1){
      ip = is_data(tokens , &i , &is_data_next);
      
    }else if(is_address_next == 1){
      ip = is_address(tokens , &i ,lt , &is_address_next);

    }else if(!strcmp(tokens[i],"MOV")){
      ip = is_mov(tokens , &i , &is_data_next);
      
    }else if(!strcmp(tokens[i],"ADD")){
      ip = is_add(tokens , &i , &is_data_next);
      
    }else if(!strcmp(tokens[i],"PRINT")){
      ip = is_print(tokens , &i , &is_data_next);
      
    }else if (tokens[i][0] == '_'){
      if((i - 1 ) < 0){
	ip = is_label(tokens , &i , &is_data_next,lt,buff_index);
      }
      else if((i - 1) > 0){
	if(strcmp(tokens[i-1],"CALL")){
	  ip = is_label(tokens , &i , &is_data_next,lt,buff_index);
	}
      }
    }
    else if(!strcmp(tokens[i],"CALL")){
      ip = is_call(tokens , &i , &is_address_next);
      
    }else if(!strcmp(tokens[i],"RET")){
      ip = is_ret(tokens , &i , &is_data_next);
      
    }else if(!strcmp(tokens[i],"JE")){
      ip = is_je(tokens , &i , &is_address_next);
      
    }else if(!strcmp(tokens[i],"JNE")){
      ip = is_je(tokens , &i , &is_address_next);
      ip.part[0] = 18;
      
    }else if(!strcmp(tokens[i],"CMP")){
      ip = is_cmp(tokens , &i , &is_address_next);
      
    }else if(!strcmp(tokens[i],"JG")){
      ip = is_jg(tokens , &i , &is_address_next);
      
    }else if(!strcmp(tokens[i],"JL")){
      ip = is_jl(tokens , &i , &is_address_next);
      
    }else if(!strcmp(tokens[i],"SUB")){
      ip = is_add(tokens , &i , &is_address_next);
      ip.part[0] = 12;
      
    }else if(!strcmp(tokens[i],"MUL")){
      ip = is_add(tokens , &i , &is_address_next);
      ip.part[0] = 14;
      
    }else if(!strcmp(tokens[i],"DIV")){
      ip = is_add(tokens , &i , &is_address_next);
      ip.part[0] = 13;
      
    }else if(!strcmp(tokens[i],"MOD")){
      ip = is_add(tokens , &i , &is_address_next);
      ip.part[0] = 15;
      
    }else if(!strcmp(tokens[i],"INC")){
      ip = is_print(tokens , &i , &is_address_next);
      ip.part[0] = 16;
      
    }else if(!strcmp(tokens[i],"DEC")){
      ip = is_print(tokens , &i , &is_address_next);
      ip.part[0] = 17;
      
    }else if(!strcmp(tokens[i],"MOVR")){
      ip = is_movr(tokens , &i , &is_address_next);
    }
    
    buffer[buff_index] = ip.data;
    buff_index++;
  }
  buffer[buff_index] = give_address( lt , "_start");
  buff_index++;
  
  u32 * new_ret = (u32 *) calloc(buff_index ,sizeof(u32));
  for(int  i = 0 ; i < buff_index ;i++){
    new_ret[i] = buffer[i];
  }

  for(int i = 0 ; i < buff_index ; i++){
    printf("%u\n",new_ret[i]);
  }
  
  free(buffer);

  raw_code retval;

  retval.code =  new_ret;
  retval.len = buff_index;

  return retval;
  
 
}
