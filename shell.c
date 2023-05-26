#include <sys/types.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#define MAX_COMMAND_LENGTH 1024

/**
 * handle_arguments - handle command with arguments
 * @args: arguments
 * @err_msg: second argument - error message
 */
void handle_arguments(char *args[], char *err_msg)
{
	pid_t pid;
	int status;

	if (_strcmp(args[0], "ls") == 0)
	{
		args[0] = "/bin/ls";
	}
	if (access(args[0], F_OK) == -1)
	{
		perror(err_msg);
		return;
	}
	pid = fork();
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
 * execute_command - handles command lines with 1 argument
 * @args: arguments
 * @err_msg: argument 2
 */
void execute_command(char *args[], char *err_msg)
{
	pid_t pid;
	int status;

	if (_strcmp(args[0], "ls") == 0)
		args[0] = "/bin/ls";
	if (access(args[0], F_OK) == -1)
	{
		perror(err_msg);
		return;
	}
	pid = fork();
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
	token = _strtok(line, " ");
	while (token != NULL && *argc < MAX_COMMAND_LENGTH - 1)
	{
		args[*argc] = token;
		(*argc)++;
		token = _strtok(NULL, " ");
	}
	args[*argc] = NULL;
}
/**
 * run_non_interactive_mode - simple shell program that displays a prompt and
 * allows the user to enters a command
 * The program continues to accept input until the user enters ctrl-D.
 * @argc: arg 1
 * @argv: arg 2
 */
void run_non_interactive_mode(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_len;
	char *err_msg = argv[0];
	char *args[MAX_COMMAND_LENGTH];

	errno = ENOENT;
	while ((read_len = getline(&line, &len, stdin)) != 1)
	{
		if (line[read_len - 1] == '\n')
			line[read_len - 1] = '\0';
		parse_input(line, args, &argc);
		if (_strcmp(args[0], "env") == 0)
			print_env_var();
		if (_strcmp(args[0], "exit") == 0 && argc == 2)
			exit_command(args);
		if (argc == 1 && (_strcmp(args[0], "env") == 0))
			execute_command(args, err_msg);
		if (argc > 1)
			handle_arguments(args, err_msg);
	}
	free(line);
}
/**
 * run_interactive_mode - executes the shell in the interactive mode
 * @argc: arg count
 * @argv: arg vector
 */
void run_interactive_mode(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_len;
	char *args[MAX_COMMAND_LENGTH];
	char *err_msg = argv[0];

	while (1)
	{
		fflush(stdout);
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		read_len = getline(&line, &len, stdin);
		if (read_len == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (line[read_len - 1] == '\n')
			line[read_len - 1] = '\0';
		argc = 0;
		parse_input(line, args, &argc);
		if (_strcmp(args[0], "env") == 0)
			print_env_var();
		if (_strcmp(args[0], "exit") == 0 && argc == 2)
			exit_command(args);
		if (argc == 1 && (_strcmp(args[0], "env") != 0))
			execute_command(args, err_msg);
		if (argc > 1)
			handle_arguments(args, err_msg);
	}
}
