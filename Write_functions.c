#include "main.h"

/**
 * write_Character - Prints character
 * @s: the char.
 * @buff: array contain string
 * @fl:  for fl.
 * @w: w.
 * @prec: prec spec
 * @sz: Size
 * Return: Number of chars.
 */
int write_Character(char s, char buff[],
	int fl, int w, int prec, int sz)
{
	int j = 0;
	char pad = ' ';

	UNUSED(prec);
	UNUSED(sz);

	if (fl & F_Z)
		pad = '0';

	buff[j++] = s;
	buff[j] = '\0';

	if (w > 1)
	{
		buff[BUFFS - 1] = '\0';
		for (j = 0; j < w - 1; j++)
			buff[BUFFS - j - 2] = pad;

		if (fl & F_M)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFFS - j - 1], w - 1));
		else
			return (write(1, &buff[BUFFS - j - 1], w - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}


/**
 * write_DIGIT - print number
 * @is_postive: check for number
 * @in: char .
 * @buff: array contain to be printed
 * @fl:  flags
 * @w: width.
 * @prec: prec specs
 * @s: Size
 * Return: Number of chars printed.
 */
int write_DIGIT(int is_postive, int in, char buff[],
	int fl, int w, int prec, int s)
{
	int L = BUFFS - in - 1;
	char pad = ' ', extra_character = 0;

	UNUSED(s);

	if ((fl & F_Z) && !(fl & F_M))
		pad = '0';
	if (is_postive)
		extra_character = '-';
	else if (fl & F_P)
		extra_character = '+';
	else if (fl & F_S)
		extra_character = ' ';

	return (write_NUMBERS(in, buff, fl, w, prec,
		L, pad, extra_character));
}

/**
 * write_NUMBERS - print numbers
 * @in: the index in buff array
 * @buff: array contain number
 * @fl: for flags
 * @w: width
 * @prec: for percision
 * @L: the length of input
 * @pad: Pading character
 * @extra_character: for extra character
 * Return: number of input
 */
int write_NUMBERS(int in, char buff[],
	int fl, int w, int prec,
	int L, char pad, char extra_character)
{
	int i, pad_st = 1;

	if (prec == 0 && in == BUFFS - 2 && buff[in] == '0' && w == 0)
		return (0);
	if (prec == 0 && in == BUFFS - 2 && buff[in] == '0')
		buff[in] = pad = ' ';
	if (prec > 0 && prec < L)
		pad = ' ';
	while (prec > L)
		buff[--in] = '0', L++;
	if (extra_character != 0)
		L++;
	if (w > L)
	{
		for (i = 1; i < w - L + 1; i++)
			buff[i] = pad;
		buff[i] = '\0';
		if (fl & F_M && pad == ' ')
		{
			if (extra_character)
				buff[--in] = extra_character;
			return (write(1, &buff[in], L) + write(1, &buff[1], i - 1));
		}
		else if (!(fl & F_M) && pad == ' ')
		{
			if (extra_character)
				buff[--in] = extra_character;
			return (write(1, &buff[1], i - 1) + write(1, &buff[in], L));
		}
		else if (!(fl & F_M) && pad == '0')
		{
			if (extra_character)
				buff[--pad_st] = extra_character;
			return (write(1, &buff[pad_st], i - pad_st) +
				write(1, &buff[in], L - (1 - pad_st)));
		}
	}
	if (extra_character)
		buff[--in] = extra_character;
	return (write(1, &buff[in], L));
}

/**
 * write_Unsignd - print Unsigned
 * @is_postive: check for number
 * @in: integer .
 * @buff: array contain to be printed
 * @fl:  flags
 * @w: width.
 * @prec: prec specs
 * @s: Size
 * Return: Number of chars printed.
 */
int write_Unsignd(int is_postive, int in,
	char buff[],
	int fl, int w, int prec, int s)
{
	int L = BUFFS - in - 1, i = 0;
	char pad = ' ';

	UNUSED(is_postive);
	UNUSED(s);

	if (prec == 0 && in == BUFFS - 2 && buff[in] == '0')
		return (0);

	if (prec > 0 && prec < L)
		pad = ' ';

	while (prec > L)
	{
		buff[--in] = '0';
		L++;
	}

	if ((fl & F_Z) && !(fl & F_M))
		pad = '0';

	if (w > L)
	{
		for (i = 0; i < w - L; i++)
			buff[i] = pad;

		buff[i] = '\0';

		if (fl & F_M)
		{
			return (write(1, &buff[in], L) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[in], L));
		}
	}

	return (write(1, &buff[in], L));
}

/**
 * write_PTR - print pointer to adress
 * @L: the length
 * @in: integer
 * @buff: array contain to be printed
 * @fl:  flags
 * @w: width.
 * @pad: for padding number
 * @extra_character: for extra charcter
 * @pad_st: the point where the padding starting
 * Return: Number of chars printed.
 */
int write_PTR(char buff[], int in, int L,
	int w, int fl, char pad, char extra_character, int pad_st)
{
	int i;

	if (w > L)
	{
		for (i = 3; i < w - L + 3; i++)
			buff[i] = pad;
		buff[i] = '\0';
		if (fl & F_M && pad == ' ')/* Asign extra char to left of buff */
		{
			buff[--in] = 'x';
			buff[--in] = '0';
			if (extra_character)
				buff[--in] = extra_character;
			return (write(1, &buff[in], L) + write(1, &buff[3], i - 3));
		}
		else if (!(fl & F_M) && pad == ' ')/* extra char to left of buff */
		{
			buff[--in] = 'x';
			buff[--in] = '0';
			if (extra_character)
				buff[--in] = extra_character;
			return (write(1, &buff[3], i - 3) + write(1, &buff[in], L));
		}
		else if (!(fl & F_M) && pad == '0')/* extra char to left of pad */
		{
			if (extra_character)
				buff[--pad_st] = extra_character;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[pad_st], i - pad_st) +
				write(1, &buff[in], L - (1 - pad_st) - 2));
		}
	}
	buff[--in] = 'x';
	buff[--in] = '0';
	if (extra_character)
		buff[--in] = extra_character;
	return (write(1, &buff[in], BUFFS - in - 1));
}
