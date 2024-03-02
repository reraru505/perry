#include "m_types.h"



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


bool isLiteral(char * s){

  if(!isAddress(s) &&
     !isReg(s) &&
     !isOpcode(s) &&
     !isDirective(s) &&
     !isLabel(s)){
    
    return true;
  }

  return false;
  
}
