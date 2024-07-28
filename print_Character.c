#include "main.h"

/**
 * printf_Character - prints character given.
 * @ptr: pointer to arguments.
 * Return: 1.
 */
int printf_Character(va_list ptr)
{
	char s;

	s = va_arg(ptr, int);
	_putchar(s);
	return (1);
}
