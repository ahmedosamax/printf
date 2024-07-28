#include "main.h"

/**
 * printf_PTR - prints an hexdecimal number.
 * @ptr: arguments to print.
 * Return: counter.
 */
int printf_PTR(va_list ptr)
{
	void *p;
	char *str = "(nil)";
	long int x;
	int y;
	int i;

	p = va_arg(ptr, void*);
	if (p == NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
		return (i);
	}

	x = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	y = printf_hex_aux(x);
	return (y + 2);
}
