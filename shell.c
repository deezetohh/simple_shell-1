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
