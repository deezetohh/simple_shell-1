#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "main.h"
#define MAX_COMMAND_LENGTH 1024

/**
 * execute_command - handls the /bin/ls
 * @args: arguments
 * @err_msg: argument 2
 */
void execute_command(char *args[], char *err_msg)
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
 * parse_input - tokenize inputs
 * @line: argument 1
 * @args: argument 2
 * @argc: argument 3
 */
void parse_input(char *line, char *args[], int *argc)
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
	int read_len;
	char *args[MAX_COMMAND_LENGTH];
	int argc;
	char *err_msg = "./shell";

	errno = ENOENT;
	while (1)
	{
		_putchar(36);
		_putchar(' ');
		fflush(stdout);
		read_len = getline(&line, &len, stdin);
		if (read_len == -1)
		{
			_putchar('\n');
			break;
		}
		if (line[read_len - 1] == '\n')
			line[read_len - 1] = '\0';
		parse_input(line, args, &argc);

		if (argc == 1 && _strcmp(args[0], "/bin/ls") == 0)
			execute_command(args, err_msg);
		/**
		 * if (argc > 1)
		 *	execute_command2();
		 */
		else
			perror(err_msg);
	}
	free(line);
	return (0);
}
