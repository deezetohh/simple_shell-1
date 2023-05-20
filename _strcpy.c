#include "main.h"
#include <string.h>

/**
 * _strcpy - Copies a string pointed by @src to the buffer pointed by @dest.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 * Return: pointer
 */
char *_strcpy(char *dest, const char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	return (p);
}
