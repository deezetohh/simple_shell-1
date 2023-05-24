#include "main.h"
#include <stddef.h>
#include <string.h>

/**
 * _strtok - Tokenizes a string based on given delimiters.
 *
 * @str: The string to be tokenized.
 * @delim: The delimiters used for tokenization.
 *
 * Return: A pointer to the next token found in the string,
 *         or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *next;
	char *start;
	const char *delimiter;

	if (str != NULL)
		next = str;
	if (next == NULL || *next == '\0')
		return (NULL);
	while (*next != '\0' && (*next == ' ' || strchr(delim, *next) != NULL))
	{
		if (*next == ' ')
			next++;
		else
			*next++ = '\0';
	}
	if (*next == '\0')
	{
		next = NULL;
		return (NULL);
	}
	start = next;
	while (*next != '\0')
	{
		delimiter = delim;
		while (*delimiter != '\0')
		{
			if (*next == *delimiter)
			{
				*next = '\0';
				next++;
				return (start);
			}
			delimiter++;
		}
		next++;
	}
	return (start);

}
