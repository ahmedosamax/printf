#include "main.h"

/**
 * printf_Octal - prints an octal number.
 * @ptr: pointer to arguments.
 * Return: count.
 */
int printf_Octal(va_list ptr)
{
	int i;
	int *arr;
	int count = 0;
	unsigned int number = va_arg(ptr, unsigned int);
	unsigned int temp = number;

	while (number / 8 != 0)
	{
		number /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 8;
		temp /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
