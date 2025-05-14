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
extern int verbose_enable;

char decompress_filepath[100] = "";

char* decompress(char* package) { // function that decompresses and installs packages
  verbose_print("Decompressing Package...\n");
  char decompress[100] = "";
  char filepath[100] = "";
  strcpy(decompress, "tar -xf ");
  strcat(decompress, package);
  // strcat(decompress, ".tar ");
  strcat(decompress, " --directory /tmp/");
  debug_print("Decompress Command = %s\n", decompress);
  system(decompress);
  debug_print("Package Name = %s\n", package);
  strcat(filepath, "/tmp/");
  strcat(filepath, package);
  int len = strlen(filepath);
  filepath[len-4] = '\0';
  debug_print("Decompressed Pacckage Filepath = %s\n",filepath);
  strcpy(decompress_filepath,filepath);
  return decompress_filepath;
}

char* xpacd_parse(char* package_folder) {
  char xpakd_file[1000];
  verbose_print("Parsing XPAKD File...\n");
  char filepath[100] = "";
  strcpy(filepath, package_folder);
  strcat(filepath, "/XPAKD");
  debug_print("XPACKD Filepath = %s\n", filepath);
  const char* file = filepath;
  FILE* fptr;
  fptr = fopen(filepath, "r");
  char buff[100];
  debug_print("XPAKD File Contents:\n\n");
  strcpy(xpakd_file, "");
  while (fgets(buff, sizeof(buff), fptr) != NULL) {
      debug_print("%s", buff);
      strcat(xpakd_file, buff);
  }
  debug_print("IGNORE needed NEWLINE (NOT IN FILE!!!\n");
  fclose(fptr);

  verbose_print("Checking Architecture...\n");

  char* target = "x86_64"; // yeah need to like make the rest of the parser its 3:45 am right now tho
  char* version;
  char* author;
  char* checksum; // yeah thats for later!




  target_check(target);

  return 0;
}
