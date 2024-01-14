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
/**
 * check_builtin - checks if a command is a built-in function
 * @cmd: command to check
 * Return: 1 if built-in, 0 otherwise
 */
int check_builtin(char *cmd)
{
	if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "env") == 0)
		return (1);
	return (0);
}

/**
 * execute_builtin - executes the built-in command
 * @cmd: command to execute
 * Return: 1 if executed, 0 otherwise
 */
int execute_builtin(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
	{
		free_cmd(cmd);
		exit_shell();
		return (1);
	}
	else if (strcmp(cmd, "env") == 0)
	{
		print_environment();
		return (1);
	}
	return (0); /* Not a built-in command */
}
