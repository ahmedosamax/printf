#include "main.h"
/**
 * _printf - function that simulates the printf function.
 * @format: a pointer to input specifiers.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	specs m[] = {
		{"%s", printf_String}, {"%c", printf_Character},
		{"%%", printf_Perc},
		{"%i", printf_Integer}, {"%d", printf_Decimal}, {"%r", printf_Reverse},
		{"%R", printf_Rot13}, {"%b", printf_b}, {"%u", printf_Nsigned},
		{"%o", printf_Octal}, {"%x", printf_hexDEC}, {"%X", printf_HEXDEC},
		{"%S", printf_exc_STRING}, {"%p", printf_PTR}
	};

	va_list ap;
	int i = 0, j, L = 0;

	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].in[0] == format[i] && m[j].in[1] == format[i + 1])
			{
				L += m[j].p(ap);
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
