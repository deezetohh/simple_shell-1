#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024

/**
 * executeCommand - handls the /bin/ls
 * @args: arguments
 * @err_msg: argument 2
 */
void executeCommand(char *args[], char *err_msg)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror(err_msg);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror(err_msg);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror(err_msg);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * parseInput - tokenize inputs
 * @line: argument 1
 * @args: argument 2
 * @argc: argument 3
 */
void parseInput(char *line, char *args[], int *argc)
{
	char *token;

	*argc = 0;
	token = strtok(line, " ");
	while (token != NULL && *argc < MAX_COMMAND_LENGTH - 1)
	{
		args[*argc] = token;
		(*argc)++;
		token = strtok(NULL, " ");
	}
	args[*argc] = NULL;
}
/**
 * _putchar - writes out a charactor in stdout
 * @c: charactor to be written in stdout
 *
 * Return: void
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * _strcmp - string comparison
 * @s1: first argument
 * @s2: second argument
 * Return: greater, less or zero based on input
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * main - simple shell program that displays a prompt and
 * allows the user to enters a command
 * The program continues to accept input until the user enters ctrl-D.
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	size_t read_len;
	pid_t pid;
	int status;
	char *args[MAX_COMMAND_LENGTH];
	int argc;
	char *token;
	char *err_meg = "./shell";

	errno = ENOENT;
	while (1)
	{
		_putchar("$");
		_putchar(" ");
		fflush(stdout);
		read_len = getline(&line, &len, stdin);
		if (read_len == -1)
		{
			_putchar("\n");
			break;
		}
		if (line[read_len - 1] == '\n')
		{
			line[read_len - 1] = '\0'
		}
		parse_input(line, args, &argc);
		if (argc == 1 && _strcmp(args[0], "/bin/ls") == 0)
		{
			execute_command(args, err_msg);
		}
		else
		{
			perror(err_msg);
		}
	}
	free(line);
	return (0);
}
