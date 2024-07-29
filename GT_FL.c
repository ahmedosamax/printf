#include "main.h"

/**
 * get_fl - fucntion for flgs
 * @ft: pointer to array of character
 * @n: pointer to integr.
 * Return: Flgs
 */
int get_fl(const char *ft, int *n)
{
	int j, cr_i;
	int fll = 0;
	const char fl_character[] = {'-', '+', '0', '#', ' ', '\0'};
	const int fl_arr[] = {F_M, F_P, F_Z, F_H, F_S, 0};

	for (cr_i = *n + 1; ft[cr_i] != '\0'; cr_i++)
	{
		for (j = 0; fl_character[j] != '\0'; j++)
			if (ft[cr_i] == fl_character[j])
			{
				fll |= fl_arr[j];
				break;
			}

		if (fl_character[j] == 0)
			break;
	}

	*n = cr_i - 1;

	return (fll);
}
