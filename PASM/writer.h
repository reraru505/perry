#pragma once
#include "opcode_selector.h"
#include "m_types.h"
#include "stdio.h"

void write_to_file(raw_code r){

  FILE *file = fopen("b.out", "wb");
  if (file == NULL) {
    printf("Error opening file!\n");
    
  }

  if (fwrite(r.code, sizeof(u32), r.len, file) != r.len) {
    printf("Error writing to file!\n");
    
  }

  fclose(file);
  
  

}
