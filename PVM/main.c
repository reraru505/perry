#include <stdio.h>


//internal

#include "loader.h"
#include "fetch.h"
#include "execute.h"

int main(int argc , char ** argv){

  if(argc < 1){
    printf("please provide a target to execute\n");
  }
  
  code_and_len code = load_bytecode(argv[1]);
  cpu * c = (cpu *) malloc(sizeof(cpu));

  
  for(int i = 0 ; i < code.len ; i++){
    printf("%d\n",code.src[i]);
  
  }

  

  
  init_cpu(c , code.src , code.len);
  printf("yo ho : %d\n\n\n",c->pc);
  init_inst();
  
  while(1){
    fetch(c,code.src);
    if(c->ip.part[0] == 0){
      break;
    }
    
    execute(c,code.src);
    
  }

  //free(c);
  free(code.src);
  
  return 0;
  
}

