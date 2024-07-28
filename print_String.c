#include "main.h"
/**
 * printf_String - print incoming string.
 * @ptr: pointer to arguments.
 * Return: the length of the string.
 */

int printf_String(va_list ptr)
{
	char *str;
	int i, L;

	str = va_arg(ptr, char *);
	if (str == NULL)
	{
		str = "(null)";
		L = _strlen(str);
		for (i = 0; i < L; i++)
			_putchar(str[i]);
		return (L);
	}
	else
	{
		L = _strlen(str);
		for (i = 0; i < L; i++)
			_putchar(str[i]);
		return (L);
	}
}
