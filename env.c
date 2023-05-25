#include "main.h"
#include <unistd.h>
#include <stddef.h>
/**
 * print_env_var - prints the environment variable
 */
void print_env_var(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
