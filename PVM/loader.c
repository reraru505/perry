#include "loader.h"

//Takes in bytecode representation 

u32 * load_bytecode(char * code){
  
  FILE * fp = fopen(code,"r");
  assert(fp != NULL);
  
  fseek(fp , 4 , SEEK_END);

  u64 f_len = ftell(fp);

  rewind(fp);

  u32 * buffer = (u32 *) calloc(f_len , sizeof(u32));

  size_t ret = fread(buffer , sizeof(buffer) * f_len , f_len , fp);
  assert(ret == f_len);
  
  fclose(fp);

  return buffer;
  
}

