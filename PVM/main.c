#include <stdio.h>


//internal

#include "loader.h"
#include "fetch.h"
#include "execute.h"

int main(int argc , char ** argv){

  if(argc < 1){
    printf("please provide a target to execute\n");
  }
  
  u32 * code = load_bytecode(argv[1]);
  cpu * c;

  
  init_cpu(c);
  init_inst();

  while(1){
    fetch(c,code);
    execute(c,code);
    
  }
  
  
  return 0;
  
}

