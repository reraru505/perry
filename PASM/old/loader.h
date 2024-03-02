#pragma once

#include "m_types.h"
#include "stdio.h"
#include "stdlib.h"
#include "tokens.h"

//Loader now tokenizes the source at load time
//welcome : )


bool m_isspace(char c){
  if(c == ' ' || c == '\n' || c == '\t'){
    return true;
  }

  return false;
}


Node * loader(char * src , Length_tracker * lt){
  
  FILE * fp = fopen(src,"r");

  if(fp == NULL){
    printf("Failed to open file named %s\n",src);
    exit(EXIT_FAILURE);
  }

  Node * head = (Node *) malloc(sizeof(Node));
  head->next = NULL;
  
  int list_len = 0;
  char c;
  
  while((c =  getc(fp)) != EOF){

    if(m_isspace(c)){
      
    }else{

      char * buffer = (char *) calloc(32, sizeof(char));

      for(int i = 0 ; i < 32 ; i++){
	if(m_isspace(c)){
	  break;
	}
	
	buffer[i] = c;
	c = getc(fp);
      }

      Node * node = (Node *) malloc(sizeof(Node));
      node->next = NULL;
      node->token.name = buffer;

        node->next = head;
	head = node;
	list_len++;

      
      
     buffer = NULL;
      
    }
  }

  lt->token_list_len = list_len;
  
  
  fclose(fp);

  return head;
}


