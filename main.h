#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct f - contain string and pointer to function
 * @in: pointer to a string
 * @p: pointer to a function
 *
 */

typedef struct f
{
	char *in;
	int (*p)();
} specs;

int printf_PTR(va_list ptr);
int printf_hexa(unsigned long int number);
int printf_HEXA(unsigned int number);
int printf_exc_STRING(va_list ptr);
int printf_HEXDEC(va_list ptr);
int printf_hexDEC(va_list ptr);
int printf_Octal(va_list ptr);
int printf_Nsigned(va_list ptr);
int printf_b(va_list ptr);
int printf_Reverse(va_list ptr);
int printf_Rot13(va_list ptr);
int printf_Integer(va_list ptr);
int printf_Decimal(va_list ptr);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlencons(const char *str);
int reverse_String(char *s);
int printf_Perc(void);
int printf_Character(va_list ptr);
int printf_String(va_list ptr);
int _putchar(char c);
int _printf(const char *format, ...);
#endif
