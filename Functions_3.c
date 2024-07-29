#include "main.h"

/**
 * print_PTR - print adress
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_PTR(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	char extra_character = 0, pad = ' ';
	int in = BUFFS - 2, L = 2, pad_start = 1;
	unsigned long NUMBER_adress;
	char too[] = "0123456789abcdef";
	void *addrs = va_arg(ptr, void *);

	UNUSED(w);
	UNUSED(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFFS - 1] = '\0';
	UNUSED(prec);

	NUMBER_adress = (unsigned long)addrs;

	while (NUMBER_adress > 0)
	{
		buff[in--] = too[NUMBER_adress % 16];
		NUMBER_adress /= 16;
		L++;
	}

	if ((fl & F_Z) && !(fl & F_M))
		pad = '0';
	if (fl & F_P)
		extra_character = '+', L++;
	else if (fl & F_S)
		extra_character = ' ', L++;

	in++;

	return (write_PTR(buff, in, L,
		w, fl, pad, extra_character, pad_start));
}

/**************************************************/
/**
 * print_N_Printed - print character which is non printable
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_N_Printed(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	int j = 0, ofs = 0;
	char *strn = va_arg(ptr, char *);

	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(s);

	if (strn == NULL)
		return (write(1, "(null)", 6));

	while (strn[j] != '\0')
	{
		if (is_PRINT(strn[j]))
			buff[j + ofs] = strn[j];
		else
			ofs += for_hexa_code(strn[j], buff, j + ofs);

		j++;
	}

	buff[j + ofs] = '\0';

	return (write(1, buff, j + ofs));
}

/**************************************************/
/**
 * print_IN_REV - print string reversly
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */

int print_IN_REV(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	char *strn;
	int j, counter = 0;

	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(s);

	strn = va_arg(ptr, char *);

	if (strn == NULL)
	{
		UNUSED(prec);

		strn = "(Null)";
	}
	for (j = 0; strn[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char z = strn[j];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}
/**************************************************/
/**
 * print_ROT13- print string in ROT 13 WAY
 * @ptr: pointer to arguments
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: Number of chars
 */
int print_ROT13(va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	char c;
	char *strn;
	unsigned int i, j;
	int counter = 0;
	char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char nop[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strn = va_arg(ptr, char *);
	UNUSED(buff);
	UNUSED(fl);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(s);

	if (strn == NULL)
		strn = "(AHYY)";
	for (i = 0; strn[i]; i++)
	{
		for (j = 0; abc[j]; j++)
		{
			if (abc[j] == strn[i])
			{
				c = nop[j];
				write(1, &c, 1);
				counter++;
				break;
			}
		}
		if (!abc[j])
		{
			c = strn[i];
			write(1, &c, 1);
			counter++;
		}
	}
	return (counter);
}
