#include "shell.h"
/**
 * find_executable - finds the executable path in the PATH directories
 * @cmd: cmd to find
 *
 * Return: full path to the executable if found, else NULL
 */
char *find_executable(char *cmd)
{
	char *path;
	char *token;
	char *path_env = getenv("PATH");

	/* Tokenize the PATH variable */
	token = strtok(path_env, ":");
	while (token != NULL)
	{
		/* Concatenate command with directory from PATH */
		path = malloc(strlen(token) + strlen(cmd) + 2);
		if (path == NULL)
		{
			perror("malloc");
			_exit(EXIT_FAILURE);
		}
		strcpy(path, token);
		strcat(path, "/");
		strcat(path, cmd);
		if (access(path, X_OK) == 0)
		{
			/* if executable file found in PATH */
			return (path);
		}
		free(path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}


/**
 * tokenize_command - tokenize the command into arguments
 * @cmd: command to tokenize
 * @arg_count: pointer to store the number of arguments
 * Return: array of arguments
 */
char **tokenize_command(char *cmd, int *arg_count)
{
	char **args;
	char *token;
	int count = 0;
	int i;

	/* Count the number of arguments */
	token = strtok(cmd, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}

	*arg_count = count;
	/* Allocate memory for arguments array */
	args = malloc((count + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	/* Tokenize the command and store arguments in args array */
	token = strtok(cmd, " ");
	for (i = 0; i < count; i++)
	{
		args[i] = token;
		token = strtok(NULL, " ");
	}
	args[count] = NULL; /* Null-terminate the array */

	return (args);
}
