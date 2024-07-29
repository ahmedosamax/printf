#include "main.h"
/**
 * h_print - for printing all inputs
 * @ft: pointer to constant string
 * @ptr: list of arguments
 * @n: pointer to integer.
 * @buff: pointer to arguments
 * @fl:  for the flags
 * @w: for the width
 * @prec: Preci spec
 * @s: Size
 * Return: 1 or 2;
 */
int h_print(const char *ft, int *n, va_list ptr, char buff[],
	int fl, int w, int prec, int s)
{
	int j, uk_L = 0, P_characters = -1;
	fmt fmt_types[] = {
		{'c', print_Character}, {'s', print_String}, {'%', print_Percentage},
		{'i', print_Integar}, {'d', print_Integar}, {'b', print_B},
		{'u', print_Nsigned}, {'o', print_Octall}, {'x', print_Hexa},
		{'X', print_HEXA}, {'p', print_PTR}, {'S', print_N_Printed},
		{'r', print_IN_REV}, {'R', print_ROT13}, {'\0', NULL}
	};
	for (j = 0; fmt_types[j].ft != '\0'; j++)
		if (ft[*n] == fmt_types[j].ft)
			return (fmt_types[j].f(ptr, buff, fl, w, prec, s));

	if (fmt_types[j].ft == '\0')
	{
		if (ft[*n] == '\0')
			return (-1);
		uk_L += write(1, "%%", 1);
		if (ft[*n - 1] == ' ')
			uk_L += write(1, " ", 1);
		else if (w)
		{
			--(*n);
			while (ft[*n] != ' ' && ft[*n] != '%')
				--(*n);
			if (ft[*n] == ' ')
				--(*n);
			return (1);
		}
		uk_L += write(1, &ft[*n], 1);
		return (uk_L);
	}
	return (P_characters);
}
