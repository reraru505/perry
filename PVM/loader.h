#pragma once
#include "stdlib.h"
#include "mytypes.h"

IP * loader(char * src ){

   FILE *file = fopen(src, "rb");

   if (file == NULL) {
     printf("Failed to open file\n");
     exit(-1);
   }

   fseek(file, 0, SEEK_END);
   long fileSize = ftell(file);
   fseek(file, 0, SEEK_SET);

   
   void *fileContents = malloc(fileSize);
   if (fileContents == NULL) {
     printf("Failed to allocate memory\n");
     fclose(file);
     exit(-1);
   }

   
   size_t result = fread(fileContents, 1, fileSize, file);
   if (result != fileSize) {
     printf("Reading error\n");
     free(fileContents);
     fclose(file);
     exit(-1);
   }

   
   fclose(file);
   
   IP  * contents = (IP*)fileContents;

   return contents;

}
