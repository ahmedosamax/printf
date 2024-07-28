#include "main.h"

/**
 * printf_HEXDEC - prints a number in hexadecimal way.
 * @ptr: arguments.
 * Return: counter to number
 */
int printf_HEXDEC(va_list ptr)
{
	int i;
	int *arr;
	int c = 0;
	unsigned int number = va_arg(ptr, unsigned int);
	unsigned int temp = number;

	while (number / 16 != 0)
	{
		number /= 16;
		c++;
	}
	c++;
	arr = malloc(c * sizeof(int));

	for (i = 0; i < c; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = c - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 7;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (c);
}
