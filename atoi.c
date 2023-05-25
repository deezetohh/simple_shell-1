#include "main.h"
/**
 * int_converter - convert string to integer
 * @str: string argument
 * Return: return converted int
 */
int int_converter(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i++] == '-') ? -1 : 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
