#include "main.h"
/**
 * get_s - for size spec
 * @ft: pointer to constant string
 * @n: pointer to integer.
 * Return: sz
 */
int get_s(const char *ft, int *n)
{
	int cr_i = *n + 1;
	int sz = 0;

	if (ft[cr_i] == 'l')
		sz = S_L;
	else if (ft[cr_i] == 'h')
		sz = S_SH;

	if (sz == 0)
		*n = cr_i - 1;
	else
		*n = cr_i;

	return (sz);
}
