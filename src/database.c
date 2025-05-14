/*Copyright 2025
Tyler McGurrin*/
#include "database.h"

#define database "/etc/xpm/database.dat"

void database_write(char* name, char* version, char* author, char* files) {
  FILE* fptr;
  fptr = fopen(database, "w+");
}

void database_print() {
  FILE* fptr;
  fptr = fopen(database, "r");
  while (fgets(buff, sizeof(buff), fptr) != NULL) {
      printf("%s", buff);
      strcat(xpakd_file, buff);
  }
}