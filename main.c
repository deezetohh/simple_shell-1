#include "main.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	if (argc > 1)
		run_non_interactive_mode(argc, argv);
	else
		run_interactive_mode(argc, argv);
	return (0);
}
