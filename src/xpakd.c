/*Copyright 2025
Tyler McGurrin*/
#include "xpakd.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "util.h"

extern int debug_enable;

char xpacd_parse(char* package_folder) {
  char filepath[100] = "";
  strcpy(filepath, package_folder);
  strcat(filepath, "/XPAKD");
  debug_print("XPACKD Filepath = %s\n", filepath);
  const char* file = filepath;
  FILE* fptr;
  fptr = fopen(filepath, "r");
  char buff[100];
  debug_print("XPAKD File Contents:\n\n");
  while (fgets(buff, sizeof(buff), fptr) != NULL) {
      debug_print("%s", buff);
  }
  fclose(fptr);
  return 0;
}
