#include "main.h"
#include <stddef.h>

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
	static char *next_token;
	char *start;
	const char *delimiter;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);

	start = next_token;

	while (*next_token != '\0')
	{
		delimiter = delim;
		while (*delimiter != '\0')
		{
			if (*next_token == *delimiter)
			{
				*next_token = '\0';
				next_token++;
				return (start);
			}
			delimiter++;
		}
		next_token++;
	}
	return (start);

}
