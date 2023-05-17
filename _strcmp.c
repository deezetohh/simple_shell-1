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
