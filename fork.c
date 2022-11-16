#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
/**
* fork_h - creates a child process and execute command
* @argv: command argument
* Return:  Always 0 on success and 1 on failure
*/
int fork_h(char **argv)
{
	pid_t fork_val;

	fork_val = fork();

	if (fork_val == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}
	if (fork_val == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			exit(1);
	}
	else
	{
		wait(NULL);
		return (0);
	}
	return (0);
}
