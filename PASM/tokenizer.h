#pragma once
#include "string.h"
#include "m_types.h"

int getBufferLen(char * code){

  int a = strlen(code);

  int retval = 0;
  
  for(int i = 0 ; i < a ; i++){
    if(code[i] == ' ' || code[i] == '\n'){
      retval++;
    }
  }

  return retval + 1;
  
}

char ** getTokens(char * code){

  int num_tokens = getBufferLen(code);
  
  int a = strlen(code);

  char ** tokens = (char **) calloc(num_tokens , sizeof(char *));

  int first = 0;
  int last = 0;
  int index = 0;
  
  while(last < a){

    if(code[last] == ' ' || code[last] == '\n'){
      int blen = last - first;
      char * buffer = (char *) calloc(blen ,sizeof(char));
      
      for(int i = 0; i < blen ; i++ ){
	buffer[i] = code[first];
	first++;
      }
      first = last+1;
      tokens[index] = buffer;
      index++;
    }

    last++;
    
  }

  
    int blen = last - first;
    char * buffer = (char *) calloc(blen ,sizeof(char));
    
    for(int i = 0; i < blen ; i++ ){
      buffer[i] = code[first];
      first++;
    }
    tokens[index] = buffer;
    
  
  return tokens;
  
}


