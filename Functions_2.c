#include "main.h"

/**
 * print_Nsigned - print number 'unsinged'
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_Nsigned(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	int j = BUFFS - 2;
	unsigned long int number = va_arg(ptr, unsigned long int);

	number = size_of_unsigned_int(number, s);

	if (number == 0)
		buff[j--] = '0';

	buff[BUFFS - 1] = '\0';

	while (number > 0)
	{
		buff[j--] = (number % 10) + '0';
		number /= 10;
	}

	j++;

	return (write_Unsignd(0, j, buff, fl, w, prec, s));
}

/*****************************/

/**
 * print_Octall - print number 'octal'
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_Octall(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{

	int j = BUFFS - 2;
	unsigned long int number = va_arg(ptr, unsigned long int);
	unsigned long int initial_number = number;

	UNUSED(w);

	number = size_of_unsigned_int(number, s);

	if (number == 0)
		buff[j--] = '0';

	buff[BUFFS - 1] = '\0';

	while (number > 0)
	{
		buff[j--] = (number % 8) + '0';
		number /= 8;
	}

	if (fl & F_H && initial_number != 0)
		buff[j--] = '0';

	j++;

	return (write_Unsignd(0, j, buff, fl, w, prec, s));
}

/****************************/
/**
 * print_Hexa - print number 'hex_lowercase'
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_Hexa(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	return (print_hexaa(ptr, "0123456789abcdef", buff,
		fl, 'x', w, prec, s));
}

/***************************/
/**
 * print_HEXA - print number 'hex_uppercase'
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_HEXA(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	return (print_hexaa(ptr, "0123456789abcdef", buff,
		fl, 'X', w, prec, s));
}

/****************************/
/**
 * print_HEXA - print number 'hex_uppercase'
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * @to: arr of chars
 * @fl_ch: arr of flags of char
 * Return: Number of chars
 */
int print_hexaa(va_list ptr, char to[],
char buff[], int fl, char fl_ch, int w, int prec, int s)
{
	int j = BUFFS - 2;
	unsigned long int number = va_arg(ptr, unsigned long int);
	unsigned long int initial_number = number;

	UNUSED(w);

	number = size_of_unsigned_int(number, s);

	if (number == 0)
		buff[j--] = '0';

	buff[BUFFS - 1] = '\0';

	while (number > 0)
	{
		buff[j--] = to[number % 16];
		number /= 16;
	}

	if (fl & F_H && initial_number != 0)
	{
		buff[j--] = fl_ch;
		buff[j--] = '0';
	}

	j++;

	return (write_Unsignd(0, j, buff, fl, w, prec, s));
}
