#include "m_types.h"
#include "string.h"

u8 give_reg(char * name){

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
  
  *current_index = *current_index + 1;

  retval.part[1] = give_reg(tokens[*current_index]);

  *data_next_signal = 1;
  
  return retval;

}

r32 is_data(char ** tokens ,
	    int * current_index,
	    int * data_next_signal){
  r32 retval;
  retval.data = atoi(tokens[*current_index]);
  *data_next_signal = 0;
  return retval;
  
}

r32 is_add(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

  r32 retval;
  retval.part[0] = 3;
  *current_index = *current_index + 1;
  retval.part[1] = give_reg(tokens[*current_index]);
  *current_index = *current_index + 1;
  retval.part[2] = give_reg(tokens[*current_index]);
  *current_index = *current_index + 1;
  retval.part[3] = give_reg(tokens[*current_index]);

  return retval;
}


r32 is_hlt(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

  r32 retval;
  retval.part[0] = 0;
  return retval;
}


r32 is_print(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

  r32 retval;
  retval.part[0] = 4;
  *current_index = *current_index + 1 ;
  retval.part[1] = give_reg(tokens[*current_index]);
  return retval;
}


r32 is_label(char ** tokens ,
	     int * current_index,
	     int * data_next_signal,
	     label_table * labels,
	     u32 buffindex){
  
  r32 retval;
  retval.part[0] = 11;
  labels->label[labels->len] = tokens[*current_index];
  labels->address[labels->len] = buffindex;
  labels->len = labels->len + 1;
  return retval;
  
}


r32 is_call(char ** tokens ,
	    int * current_index,
	    int * address_next_signal){
  r32 retval;
  retval.part[0] = 5;
  *address_next_signal = 1;
  return retval;
}

u32 give_address(label_table * lt , char * label){

  for(int i = 0 ; i < lt->len ; i++){
    if(!strcmp(lt->label[i],label)){
      return lt->address[i];
    }
  }
  
}


r32 is_address(char ** tokens ,
	       int * current_index,
	       label_table * lt,
	       int * address_next_signal){
  r32 retval;
  retval.data = give_address(lt,tokens[*current_index]);
  *address_next_signal = 0;
  return retval;
  
}


r32 is_ret(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){
  r32 retval;
  retval.part[0] = 6;
  return retval;
  
}


r32 is_cmp(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

}


r32 is_je(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

}


r32 is_jg(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

}


r32 is_jl(char ** tokens ,
	   int * current_index,
	   int * data_next_signal){

}
