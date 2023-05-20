#include "main.h"

/**
 * _printf - Brief description of the function.
 * @str: string char
 * Return: void
 */
void _printf(const char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
