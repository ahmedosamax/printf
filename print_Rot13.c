#include "main.h"
/**
 * printf_Rot13 - print shifted string
 * @ptr: type struct va_arg where is allocated printf arguments
 * Return: count
 */
int printf_Rot13(va_list ptr)
{
	int i, j, count = 0;
	int L = 0;
	char *str = va_arg(ptr, char*);
	char abc[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char noq[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		L = 0;
		for (j = 0; abc[j] && !L; j++)
		{
			if (str[i] == abc[j])
			{
				_putchar(noq[j]);
				count++;
				L = 1;
			}
		}
		if (!L)
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
