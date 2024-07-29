#include "main.h"
/**
 * _strlen - calcu the lenght of string.
 * @str: Type char pointer
 * Return: the lenght.
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);

}
/**
 * _strlencons - Strlen function to get the length
 * @str: Type char pointer
 * Return: the length
 */
int _strlencons(const char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}
