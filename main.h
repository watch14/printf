#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>


#define BUFF_SIZE 1024


int _printf(const char *format, ...);
int check(char f, char *s, int nbch);
int str_len(char *str);





#endif
