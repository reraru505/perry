#pragma once

#include "ctype.h"
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

char * strip_space(char * c , int len){
  int counter = 0 ;
  
  for (int i = 0 ; i < len ; i++){
    if(c[i] == ' ' || c[i] == '\n' || c[i] == '\t'){
      counter ++;
    }
  }

  char * retval = (char * ) calloc(counter , sizeof(char));

  int index = 0 ;
  for (int i = 0 ;  i < len ; i++){
    if(c[i] != ' ' || c[i] != '\n' || c[i] != '\t'){
      retval[index] = c[i];
      index++;
    }
  }

  return retval;
}

token remove_blank_tokens(char ** tokens , int len){

  int counter = 0;
  
  for (int i = 0 ; i < len ; i++){
    if(tokens[i][0] != '\0'){
      counter++;
    }
  }
  
  char ** retval = (char **) calloc(counter , sizeof(char *));

  int index = 0;
  
  for (int i = 0 ; i < len ; i++){
    if(tokens[i][0] != '\0'){
      retval[index] = tokens[i];
      //free(tokens[i]);
      index++;
    }
  }
  
  free(tokens);


  token t;
  t.tokens = retval;
  t.len  = counter;
  
  return t;

}


token getTokens(char * code){

  int num_tokens = getBufferLen(code);
  
  int a = strlen(code);

  char ** tokens = (char **) calloc(num_tokens , sizeof(char *));

  int first = 0;
  int last = 0;
  int index = 0;
  
  while(last < a){

    if(code[last] == ' ' || code[last] == '\n' || code[last] == '\t'){

      int blen = last - first;
      char * buffer = (char *) calloc(blen ,sizeof(char));
      
      for(int i = 0; i < blen ; i++ ){
	buffer[i] = code[first];
	first++;
	
	
      }

      first = last+1;
      char * retval = strip_space(buffer, blen);
      free(buffer);
      tokens[index] = retval;
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
 

  
  return remove_blank_tokens(tokens,num_tokens);
  
}

