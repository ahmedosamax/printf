#include "main.h"
/**
 * printf_Integer - prints integer
 * @ptr: argument to print
 * Return: number of characters printed
 */
int printf_Integer(va_list ptr)
{
	int x = va_arg(ptr, int);
	int number, last_number = x % 10, d, e = 1;
	int  i = 1;

	x = x / 10;
	number = x;

	if (last_number < 0)
	{
		_putchar('-');
		number = -number;
		x = -x;
		last_number = -last_number;
		i++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			e = e * 10;
			number = number / 10;
		}
		number = x;
		while (e > 0)
		{
			d = number / e;
			_putchar(d + '0');
			number = number - (d * e);
			e = e / 10;
			i++;
		}
	}
	_putchar(last_number + '0');

	return (i);
}
