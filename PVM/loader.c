#include "loader.h"
 

u32 * load_bytecode(char * code){
  
  FILE *file = fopen(code, "rb");
  if (file == NULL) {
    printf("Error opening file!\n");
  }
    
  fseek(file, 0, SEEK_END);
  size_t fileSize = ftell(file);
  rewind(file);

  size_t numElements = fileSize / sizeof(u32);
  
  u32 *array = (u32 *)calloc(numElements , sizeof(u32));
  
  if (array == NULL) {
    printf("Error allocating memory!\n");
  }

  size_t ret = fread(array, sizeof(u32), numElements, file);
  if (ret != numElements) {
    printf("Error reading file!\n");
  }


  fclose(file);

  return array;
}

