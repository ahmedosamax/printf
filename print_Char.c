#include "main.h"
/**
 * print_Char - prints a char.
 * @ptr: pointer to the argument.
 * Return: 1.
 */
int print_Char(va_list ptr)
{
	char i;
	char i = va_arg(ptr, char);

	_putchar(i);
	return (1);
}
