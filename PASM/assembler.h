#pragma once


typedef struct Assembler{

  Length_tracker * len_tracker;
  char * src;
  
  Node * head;
  Token * token_array;

  
} Assembler;

void assembler_init(Assembler * as ,  char * src){

  as->len_tracker = (Length_tracker *) malloc(sizeof(Length_tracker));
  as->src = src;  

}

void assembler_run(Assembler * as){

  //loading stage
  as->head = loader(as->src , as->len_tracker);
  as->token_array = flatten_token_list(as->head ,as->len_tracker);

}
void assembler_end(Assembler * as);
