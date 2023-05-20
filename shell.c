#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "main.h"
#define MAX_COMMAND_LENGTH 1024

/**
 * execute_command - handles command lines with 1 argument
 * @args: arguments
 * @err_msg: argument 2
 */
void execute_command(char *args[], char *err_msg)
{
	pid_t pid;
	int status;

	if (_strcmp(args[0], "exit") == 0)
	{
		_putchar('\n');
		_printf("Goodbye...\n");
		exit(0);
	}
	pid = fork();
	if (_strcmp(args[0], "ls") == 0)
		_strcpy(args[0], "/bin/ls");
	if (pid < 0)
	{
		perror(err_msg);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(err_msg);
			exit(EXIT_FAILURE);
		}
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
 * main - simple shell program that displays a prompt and
 * allows the user to enters a command
 * The program continues to accept input until the user enters ctrl-D.
 * @argc: arg 1
 * @argv: arg 2
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_len;
	char *args[MAX_COMMAND_LENGTH];
	char *err_msg = "./shell";

	(void)argv;
	errno = ENOENT;
	while (1)
	{
		_putchar('$');
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

		if (argc == 1)
			execute_command(args, err_msg);
	}
	free(line);
	return (0);
}
