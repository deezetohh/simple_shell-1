#include "main.h"
/**
 * _strlen - get the length of a string
 * @s: string argument
 * Return: returns length of string
 */
int _strlen(char *s)
{
	int i;
	int length = 0;

	for (i = 0; s[i] != '\0'; ++i)
	{
		length++;
	}
	return (length);
}
