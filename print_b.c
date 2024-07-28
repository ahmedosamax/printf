#include "main.h"

/**
 * printf_b - prints a binary number.
 * @ptr: arguments.
 * Return: 1.
 */
int printf_b(va_list ptr)
{
	int flag = 0;
	int cont = 0;
	int i, x = 1, y;
	unsigned int number = va_arg(ptr, unsigned int);
	unsigned int l;

	for (i = 0; i < 32; i++)
	{
		l = ((x << (31 - i)) & number);
		if (l >> (31 - i))
			flag = 1;
		if (flag)
		{
			y = l >> (31 - i);
			_putchar(y + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}
