#include "main.h"

void p_buff(char buff[], int *buff_in);

/**
 * _printf - function that simulate printf function
 * @format: the given.
 * Return: the number of pr chars.
 */
int _printf(const char *format, ...)
{
	int j, pr = 0, pr_character = 0;
	int fl, w, prec, s, buff_in = 0;
	va_list ptr;
	char buff[BUFFS];

	if (format == NULL)
		return (-1);

	va_start(ptr, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buff[buff_in++] = format[j];
			if (buff_in == BUFFS)
				p_buff(buff, &buff_in);
			pr_character++;
		}
		else
		{
			p_buff(buff, &buff_in);
			fl = get_fl(format, &j);
			w = get_w(format, &j, ptr);
			prec = get_prec(format, &j, ptr);
			s = get_s(format, &j);
			++j;
			pr = h_print(format, &j, ptr, buff,
				fl, w, prec, s);
			if (pr == -1)
				return (-1);
			pr_character += pr;
		}
	}
	p_buff(buff, &buff_in);

	va_end(ptr);

	return (pr_character);
}

/**
 * p_buff -print the content of array buff if found
 * @buff: pointer to array of character
 * @buff_in: Index of the nex character.
 */
void p_buff(char buff[], int *buff_in)
{
	if (*buff_in > 0)
		write(1, &buff[0], *buff_in);

	*buff_in = 0;
}
