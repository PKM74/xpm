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
  char decompress[100] = "";
  char filepath[100] = "";
  strcpy(decompress, "tar -xf ");
  strcat(decompress, package);
  // strcat(decompress, ".tar ");
  strcat(decompress, "--directory /tmp/");
  debug_print("Decompress Command = %s\n", decompress);
  system(decompress);
  debug_print("Package Name = %s\n", package);
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