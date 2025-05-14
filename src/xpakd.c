/*Copyright 2025
Tyler McGurrin*/
#include "xpakd.h"

#include <stdlib.h>
#include <stdio.h>

char xpacd_parse(char* file) {

  FILE *fptr = fopen(file, "r");
  if (fptr == NULL) { 
    printf("Invalid XPAKD File, Contents NULL\n");
    return -1;  
  }

  char ch;
  while ((ch = fgetc(fptr)) != EOF) {
    putchar(ch); 
  }

  fclose(fptr);
  return 0;
}
