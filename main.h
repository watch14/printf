#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int check(char specifier, va_list args, int count);
int str_len(char *str);
int check_c(va_list args, int count);
int check_s(va_list args, int count);
int check_d(va_list args, int count);
int check_b(va_list args, int count);

#endif
