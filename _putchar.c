#include <unistd.h>

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
