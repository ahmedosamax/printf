#include "main.h"

/**
 * get_prec - for perc
 * @ft: pointer to cons string
 * @n: pointer to integer.
 * @ptr: the list of arguments.
 * Return: Prec.
 */
int get_prec(const char *ft, int *n, va_list ptr)
{
	int cr_i = *n + 1;
	int perci = -1;

	if (ft[cr_i] != '.')
		return (perci);

	perci = 0;

	for (cr_i += 1; ft[cr_i] != '\0'; cr_i++)
	{
		if (is_number(ft[cr_i]))
		{
			perci *= 10;
			perci += ft[cr_i] - '0';
		}
		else if (ft[cr_i] == '*')
		{
			cr_i++;
			perci = va_arg(ptr, int);
			break;
		}
		else
			break;
	}

	*n = cr_i - 1;

	return (perci);
}
