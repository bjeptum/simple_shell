#include "shell.h"
/**
 * execute_child - executes the command in the child process
 * @args: array of arguments
 * Return: 0 on success
 */
void execute_child(char **args)
{
	if (access(args[0], X_OK) == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char *path = find_executable(args[0]);

		if (path != NULL)
		{
			if (execve(path, args, NULL) == -1)
			{
				perror("execve");
				free(path);
				free(args);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * execute_cmd - executes given command
 * @cmd: command to execute
 * Return: void
 */
void execute_cmd(char *cmd)
{
	char **args;
	int arg_count;
	int status;
	pid_t pid = fork();

	if (check_builtin(cmd))
	{
		execute_builtin(cmd);
	}
	else
	{
		do {
			if (pid == -1)
			{
				perror("Fork failed");
				_exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				/* In the child process */
				args = tokenize_command(cmd, &arg_count);
				execute_child(args);
			}
			else
			{
				/* In the parent process */
				waitpid(pid, &status, 0);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
