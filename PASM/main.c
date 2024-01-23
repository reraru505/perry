#include <stdio.h>
#include "loader.h"
#include "tokenizer.h"
#include "opcode_selector.h"
#include "writer.h"

int main(int argc , char ** argv ){

  

  char * buffer = loader(argv[1]);
  char ** tokens = getTokens(buffer);

  int l = getBufferLen(buffer);
  
  raw_code r = opcode_selector(tokens , l);
  write_to_file(r);
  
  return 0;
  
}
