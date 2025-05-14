/*Copyright 2025
Tyler McGurrin*/
#include "util.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "xpakd.h"

extern int debug_enable;

int install(char* package) { // function that decompresses and installs packages
  char* decompress;
  char* filepath;
  strcpy(decompress, "tar -xf ");
  strcat(decompress, package);
  strcat(decompress, ".tar ");
  // strcat(decompress, "-C /tmp/");
  // strcat(decompress, package);
  // system(decompress);
  debug_print("Decompress Command = %s\nPackage = %s\n", decompress, package);
  strcat(filepath, "/tmp/");
  strcat(filepath, package);
  debug_print("Decompressed Pacckage Filepath = %s\n",filepath);
  
  char install = xpacd_parse(filepath);
}

void debug_print(const char* fmt, ...) {
  if (debug_enable == true) {
    va_list args;
    va_start(args, fmt);
    printf("DEBUG : ");
    vprintf(fmt, args);
    va_end(args);
  } else {
    return;
  }
  return;
}