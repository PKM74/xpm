/*Copyright 2025
Tyler McGurrin*/
#include "database.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "util.h"
#include "xpakd.h"

#define database "/etc/xpm/database.dat"

extern int debug_enable;
extern int verbose_enable;

void database_write(char* name, char* version, char* author, char* files) {
  FILE* fptr;
  fptr = fopen(database, "a");
  fprintf(fptr, "%s\a%s\a%s\a%s\n", name, version, author, files);
  fclose(fptr);
}

void database_print() {
  char* file_contents;
  char buff[100];
  FILE* fptr;
  fptr = fopen(database, "r");
  while (fgets(buff, sizeof(buff), fptr) != NULL) {
      printf("%s", buff);
      strcat(file_contents, buff);
  }
}

void database_remove(char* name) { //not sure if this works its currently unused...
  int i=0;
  FILE* fptr;
  char* file_contents;
  char buff[100];
  fptr = fopen(database, "w+");
  while (fgets(buff, sizeof(buff), fptr) != NULL) {
      strcat(file_contents, buff);
  }
  name[strlen(name)-1]='\0';
  if (strstr(file_contents,name))
  {
          printf("substring is present\t");
  }
  printf("and the sub string is:::");
  printf("%s",name,"\n");
  return;
}