#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>




int _printf(const char *format, ...);
int check(char specifier, va_list args, int count);




#endif
