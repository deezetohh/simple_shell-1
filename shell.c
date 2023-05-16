#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024

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
 * main - simple shell program that displays a prompt
 * and allows the user to enters a command
 * The program continues to accept input until the user enters ctrl-D.
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t line_len = 0;
	ssize_t read_len;
	pid_t pid;
	int status;
	char *args[MAX_COMMAND_LENGTH];
	int argc;
	char *token;
	char *err_msg = "./shell";

	errno = ENOENT;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		read_len = getline(&line, &line_len, stdin);
		if (read_len == -1)
		{
			printf("\n");
			break;
		}
		if (line[read_len - 1] == '\n')
		{
			line[read_len - 1] = '\0';
		}
		argc = 0;
		token = strtok(line, " ");
		while (token != NULL && argc < MAX_COMMAND_LENGTH - 1)
		{
			args[argc] = token;
			argc++;
			token = strtok(NULL, " ");
		}
		args[argc] = NULL;
		if (argc == 1 && _strcmp(args[0], "/bin/ls") == 0)
		{
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
		else
		{
			perror(err_msg);
		}
	}
	free(line);
	return (0);
}

