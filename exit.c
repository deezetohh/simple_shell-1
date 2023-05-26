#include "main.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * exit_command - handles exit command argument
 * @args: arguments
 *
 */
void exit_command(char **args)
{
	int status;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = int_converter(args[1]);
			exit(status);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
}
