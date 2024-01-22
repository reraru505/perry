#include "m_types.h"
#include "string.h"

int give_reg(char * name){

  if(!strcmp(name,"A")){
    return 0;
  }else if(!strcmp(name,"B")){
    return 1;
  }else if(!strcmp(name,"C")){
    return 2;
  }else if(!strcmp(name,"D")){
    return 3;
  }else if(!strcmp(name,"E")){
    return 4;
  }else if(!strcmp(name,"F")){
    return 5;
  }else if(!strcmp(name,"G")){
    return 6;
  }else if(!strcmp(name,"H")){
    return 7;
  }
  
}

r32 is_mov(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

  r32 retval;

  retval.part[0] = 1;
  
  *current_index++;

  retval.part[1] = give_reg(tokens[*current_index]);

  *data_next_signal = 1;
  
  return retval;

}

r32 is_data(char ** tokens ,
	    int * current_index,
	    int * data_next_signal){
  r32 retval.data = atoi(tokens[*current_index]);
  *data_next_signal = 0;
  return retval;
  
}

r32 is_add(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

  r32 retval;
  retval.part[0] = 3;
  *current_index++;
  retval.part[1] = give_reg(tokens[*current_index]);
  *current_index++;
  retval.part[2] = give_reg(tokens[*current_index]);
  *current_index++;
  retval.part[3] = give_reg(tokens[*current_index]);

  return retval;
}

