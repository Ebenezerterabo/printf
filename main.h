#ifndef MAIN_H
#define MAIN_H

/* Standard C library */
#include <stdarg.h>
#include <unistd.h>

#define BUF_SIZE 1024
/* Function Prototypes */
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_str(va_list ap);
int check_cases(va_list ap, const char *format);
int _strlen(char *str);
int _putchr(char c);
int put_int(int num);

#endif
