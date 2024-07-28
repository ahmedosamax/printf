#include "main.h"
/**
 * _printf - function that simulate the printf function
 * @format: arguments that given
 * Return: the length of input.
 */
int _printf(const char * const format, ...)
{
	specs m[] = {
		{"%s", print_String}, {"%c", print_Char},
		{"%%", print_Perc},
		{"%i", printf_Integer}, {"%d", printf_Decimals},
	};

	va_list ap;
	int i = 0, j, L = 0;

	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 4;
		while (j >= 0)
		{
			if (m[j].in[0] == format[i] && m[j].in[1] == format[i + 1])
			{
				L += m[j].ptr(ap);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		L++;
		i++;
	}
	va_end(ap);
	return (L);
}
