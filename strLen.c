#include"main.h"
/**
 * _strlen - int function calculate the len of string
 * @s: pointer to the string
 * Return: counter
 */
int _strlen(char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}
