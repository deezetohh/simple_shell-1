#include "main.h"

/**
 * _strlen - gets the lenght of th string
 * @s: string pointer
 *
 * Return: pointer
 */
int _strlen(char *s)
{
	int len = 0, i = 0;

	while (s[i++] != '\0')
	{
		len++;
	}
	return (len);
}
