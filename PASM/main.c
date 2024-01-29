#include <stdio.h>
#include "loader.h"
#include "tokenizer.h"
#include "opcode_selector.h"
#include "writer.h"
#include "tokens.h"

int main(int argc , char ** argv ){


  Length_tracker * len_tracker = (Length_tracker *)
    malloc(sizeof(Length_tracker));

  Node * buffer = loader(argv[1] , len_tracker);

  Token * tok_array = flatten_token_list(buffer , len_tracker);

  for ( int i = 0 ; i < len_tracker->token_list_len ;  i++){
    printf("%s\n",tok_array[i].name);
  }
  
  return 0;
  
}
