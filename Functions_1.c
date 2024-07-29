#include "main.h"
/**
 * print_Character - handling single characters
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl: for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of char
 */
int print_Character(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	char c = va_arg(ptr, int);

	return (write_Character(c, buff, fl, w, prec, s));
}
/**************************************************/

/**
 * print_String - handle printing strings
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_String(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	int L = 0, i;
	char *strr = va_arg(ptr, char *);

	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(s);
	if (strr == NULL)
	{
		strr = "(null)";
		if (prec >= 6)
			strr = "      ";
	}

	while (strr[L] != '\0')
		L++;

	if (prec >= 0 && prec < L)
		L = prec;

	if (w > L)
	{
		if (fl & F_M)
		{
			write(1, &strr[0], L);
			for (i = w - L; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - L; i > 0; i--)
				write(1, " ", 1);
			write(1, &strr[0], L);
			return (w);
		}
	}

	return (write(1, strr, L));
}
/**************************************************/
/**
 * print_Percentage - Prints '%'
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width.
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_Percentage(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	UNUSED(ptr);
	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(s);
	return (write(1, "%%", 1));
}

/**************************************************/
/**
 * print_Integar - Print number 'integar
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w:for the width.
 * @prec: Preci spec
 * @s: Size specifier
 * Return: Number of chars
 */
int print_Integar(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	int i = BUFFS - 2;
	int is_N = 0;
	long int num = va_arg(ptr, long int);
	unsigned long int number;

	num = size_of_number(num, s);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFFS - 1] = '\0';
	number = (unsigned long int)num;

	if (num < 0)
	{
		number = (unsigned long int)((-1) * num);
		is_N = 1;
	}

	while (number > 0)
	{
		buff[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_DIGIT(is_N, i, buff, fl, w, prec, s));
}

/**************************************************/
/**
 * print_B - Print number 'binary'
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w:for the width.
 * @prec: Preci spec
 * @s: Size specifier
 * Return: Number of chars
 */
int print_B(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	unsigned int n, x, i, Sum;
	unsigned int arr[32];
	int counter;

	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(s);

	n = va_arg(ptr, unsigned int);
	x = 2147483648; /* (2 ^ 31) */
	arr[0] = n / x;
	for (i = 1; i < 32; i++)
	{
		x /= 2;
		arr[i] = (n / x) % 2;
	}
	for (i = 0, Sum = 0, counter = 0; i < 32; i++)
	{
		Sum += arr[i];
		if (Sum || i == 31)
		{
			char z = '0' + arr[i];

			write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}
