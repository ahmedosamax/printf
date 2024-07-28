#include "main.h"

/**
 * printf_Reverse - function print reversed string
 * @ptr: type struct va_arg where is allocated printf arguments
 * Return:  pointer to the string
 */
int printf_Reverse(va_list ptr)
{

	char *str = va_arg(ptr, char*);
	int i;
	int j = 0;

	if (str == NULL)
		str = "(null)";
	while (str[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(str[i]);
	return (j);
}
