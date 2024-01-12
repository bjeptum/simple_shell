#include "shell.h"
/**
 * execute_cmd - executes given command
 * @cmd: command to execute
 *
 * Return: void
 */
void execute_cmd(char *cmd)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		_exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		/* In the child process */
		char **args = malloc(2 * sizeof(char *));

		if (args == NULL)
		{
			perror("malloc");
			_exit(EXIT_FAILURE);
		}
		args[0] = cmd;
		args[1] = NULL;

		execve(cmd, args, NULL);
		perror("execve");

		free(args);
		_exit(EXIT_FAILURE);
	}
	else
	{
		/* In the parent proces */
		wait(NULL);
	}
}
