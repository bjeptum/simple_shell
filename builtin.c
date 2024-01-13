#include "shell.h"
/**
 * exit_shell- handles the exit built-in
 * Return: 0 on success
 */
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}


/**
 * print_environment - handles the built-in env
 * Return: 0 on success
 */
void print_environment(void)
{
	char **env = environ;

	while (env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
