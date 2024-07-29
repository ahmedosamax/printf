#include "main.h"
/**
 * printf_exc_STRING - print exclusuives string.
 * @ptr: argumen t.
 * Return: the length of the string.
 */

int printf_exc_STRING(va_list ptr)
{
	char *str;
	int i, L = 0;
	int cs;

	str = va_arg(ptr, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			L = L + 2;
			cs = str[i];
			if (cs < 16)
			{
				_putchar('0');
				L++;
			}
			L = L + printf_HEXA(cs);
		}
		else
		{
			_putchar(str[i]);
			L++;
		}
	}
	return (L);
}
