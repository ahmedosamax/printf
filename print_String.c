#include "main.h"
/**
 * print_String - prints a string.
 * @ptr: pointer to the argument.
 * Return: the length of the string.
 */
int print_String(va_list ptr)
{
	char *j;
	int i, L;

	j = va_arg(ptr, char *);
	if (!j)
	{
		j = "(null)";
		L = _strlen(j);
		for (i = 0; i < j; i++)
			_putchar(j[i]);
		return (L);
	}
	for (i = 0; j[i] != '\0'; i++)
		_putchar (j[i]);
	L = _strlen(j);
	return (L);
}
