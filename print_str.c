#include "main.h"
/**
 * _strlen - Returns the lenght of a string.
 * @str: Type char pointer
 * Return: i.
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);

}
/**
 * _strlenc - Strlen function but applied for constant char pointer str
 * @str: Type char pointer
 * Return: i
 */
int _strlencons(const char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}
