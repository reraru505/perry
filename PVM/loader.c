#include "loader.h"


u32 * load_bytecode(char * code){
  
  FILE * fp = fopen(code,"r");
  assert(fp != NULL);
  
  fseek(fp , SEEK_END , 0);

  u64 f_len = ftell(fp);

  rewind(fp);

  u32 * buffer = (u32 *) calloc(f_len , sizeof(u32));

  size_t ret = fread(buffer , sizeof(buffer) * f_len , f_len , fp);
  assert(ret == f_len);
  
  fclose(fp);

  return buffer;
  
}

