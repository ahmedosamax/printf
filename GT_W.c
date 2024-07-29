#include "main.h"

/**
 * get_w- for w_d specifier
 * @ft: pointer to constant string
 * @n: pointer to integer
 * @ptr: list of argus.
 * Return: w.
 */
int get_w(const char *ft, int *n, va_list ptr)
{
	int cr_i;
	int w_d = 0;

	for (cr_i = *n + 1; ft[cr_i] != '\0'; cr_i++)
	{
		if (is_number(ft[cr_i]))
		{
			w_d *= 10;
			w_d += ft[cr_i] - '0';
		}
		else if (ft[cr_i] == '*')
		{
			cr_i++;
			w_d = va_arg(ptr, int);
			break;
		}
		else
			break;
	}

	*n = cr_i - 1;

	return (w_d);
}
