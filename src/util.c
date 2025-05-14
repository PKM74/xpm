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
extern int verbose_enable;

void install(char* package) {
  char* filepath = decompress(package);
  char* xpakd = xpacd_parse(filepath);
}

int target_check(char* target) {
FILE *fp;
char path[1035];

/* Open the command for reading. */
fp = popen("uname -m", "r");
if (fp == NULL) {
  printf("Failed to get System ARCHITECTURE\n" );
  exit(1);
}
char system[1035] = "";
/* Read the output a line at a time - output it. */
while (fgets(path, sizeof(path), fp) != NULL) {
  strcat(system, path);
}
debug_print("System Arch = %s", system);
debug_print("Program Arch = %s\n", target);
if (target == system) {
  return true;
}

/* close */
pclose(fp);

return 0;
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

void verbose_print(const char* fmt, ...) {
  if (verbose_enable == true) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
  } else {
    return;
  }
  return;
}

char* string_parse(char* string, char* substring) {
  char* substr;
  char retstr[50] = "";
  char buffer[1000] = "";
  debug_print("String Parse String:\n%s\n", string);
  strcpy(string, substr);
  substr[strlen(substr)-1]='\0';
  if (strstr(string, substr))
  {
    strcpy(buffer, string);
    for (;;) {
      int n = 0;
      char buf[1] = "";
      // if (buf == "\0") break;

      n++;
      break; // remove later and make buf get one byte at a time from buffer

    }
    debug_print("Substring is Present\n");
    // return retstr;
  }
  return "NULL";
}