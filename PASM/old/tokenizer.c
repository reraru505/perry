#include "tokenizer.h"
#include "stdio.h"


Token * flatten_token_list(Node * n , Length_tracker * lt){

  Token * tok_array = (Token * ) calloc(lt->token_list_len,
					sizeof(Token));

  for(int i = (lt->token_list_len - 1) ; i > -1 ; i-- , n = n->next){

    tok_array[i] = n->token;
  }
  
  return tok_array;
  
}



bool isOpcode(char * s){
  if(!strcmp(s,"mov") ||
     !strcmp(s,"hlt") ||
     !strcmp(s,"add") ||
     !strcmp(s,"sub") ||
     !strcmp(s,"mul") ||
     !strcmp(s,"div") ||
     !strcmp(s,"mod") ||
     !strcmp(s,"call") ||
     !strcmp(s,"ret") ||
     !strcmp(s,"cmp") ||
     !strcmp(s,"je") ||
     !strcmp(s,"jne") ||
     !strcmp(s,"jge") ||
     !strcmp(s,"jle") ||
     !strcmp(s,"push") ||
     !strcmp(s,"pop") ||
     !strcmp(s,"syscall")){
    return true;
  }

  return false;
}


bool isReg(char * s){

  if(s[0] == '%'){
    return true;
  }

  return false;
  
}

bool isAddress(char * s){

  if(s[0] == '&'){
    return true;
  }

  return false;
  
}


bool isDirective(char * s){

  if(s[0] == '.'){
    return true;
  }

  return false;
  
}

bool isLabel(char * s){

  if(s[0] == '_'){
    return true;
  }

  return false;
}


bool isData(char * s){

  if(!isAddress(s) &&
     !isReg(s) &&
     !isOpcode(s) &&
     !isDirective(s) &&
     !isLabel(s)){
    
    return true;
  }

  return false;
  
}
