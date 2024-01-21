#include <stdio.h>
#include "loader.h"
#include "tokenizer.h"

int main(int argc , char ** argv ){

  

  char * buffer = loader(argv[1]);
  char ** tokens = getTokens(buffer);

  int l = getBufferLen(buffer);

  for(int i = 0 ; i < l ; i++ ){
    printf("%s\n",tokens[i]);
  }

  return 0;
  
}
