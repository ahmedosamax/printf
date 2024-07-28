#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
/**
 * struct format - pointer to string and pointer to function
 * @in: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @ptr: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *in;
	int (*ptr)();
} specs;
int _putchar(char c);
int _strlen(char *s);
int print_Char(va_list ptr);
int print_String(va_list ptr);
int print_Perc(void);
int printf_Integer(va_list ptr);
int printf_Decimals(va_list ptr);
int _printf(const char *format, ...);
#endif
