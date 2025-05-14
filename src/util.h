/*Copyright 2025
Tyler McGurrin*/
#pragma once

void install(char* package);
void debug_print(const char* fmt, ...);
void verbose_print(const char* fmt, ...);
int target_check(char* target);
char* string_parse(char* string, char* substring);