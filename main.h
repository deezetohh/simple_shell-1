#ifndef MAIN_H
#define MAIN_H
void _putchar(char c);
int _strcmp(char *s1, char *s2);
void free_args(char *args[]);
char *_strcpy(char *dest, const char *src);
void _printf(const char *str);
extern char **environ;
int _strlen(char *s);
char *_strtok(char *str, const char *delim);

#endif

