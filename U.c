#include "main.h"

/**
 * is_PRINT - check for string printablty
 * @s: Char to be evaluated.
 * Return: 1 for TRUTH 0 for FALSE
 */
int is_PRINT(char s)
{
	if (s >= 32 && s < 127)
		return (1);

	return (0);
}

/**
 * for_hexa_code - put ascii in hexadecimal
 * @buff: an array of character.
 * @n: index for appending.
 * @ascii: the ASSCI CODE.
 * Return: 3
 */
int for_hexa_code(char ascii, char buff[], int n)
{
	char to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii < 0)
		ascii *= -1;

	buff[n++] = '\\';
	buff[n++] = 'x';

	buff[n++] = to[ascii / 16];
	buff[n] = to[ascii % 16];

	return (3);
}

/**
 * is_number - check for number
 * @s: the input to be checked
 * Return: 1 for TRUTH 0 for False
 */
int is_number(char s)
{
	if (s >= '0' && s <= '9')
		return (1);

	return (0);
}

/**
 * size_of_number - function give the s of number
 * @number: the input number
 * @s: number for the type of cast
 * Return: number after casting
 */
long int size_of_number(long int number, int s)
{
	if (s == S_L)
		return (number);
	else if (s == S_SH)
		return ((short)number);

	return ((int)number);
}

/**
 * size_of_unsigned_int - for casting numbers
 * @number: the input number to be casted
 * @s: Number for indcate the cast
 * Return: number after being casted
 */
long int size_of_unsigned_int(unsigned long int number, int s)
{
	if (s == S_L)
		return (number);
	else if (s == S_SH)
		return ((unsigned short)number);
	return ((unsigned int)number);
}
