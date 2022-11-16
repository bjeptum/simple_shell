#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
/**
* main - loops through read command and executes
*
* Return: output of command inputted
*/
int main(int argc, char **argv, char * envp[])
{
	char *cmd;

	do
	{
		cmd = read_cmd();

		if (!cmd)
		{
			exit(EXIT_SUCCESS);
		}
		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}
		if (strcmp(cmd,"exit\n") == 0)
		{
			free(cmd);
			break;
		}
		printf("%s\n",cmd);

		free(cmd);
	}while(1);

/**
* main - allows a process to execute another program
*
*/
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	argv[0] = argv[1];

	execve(argv[1], argv, envp);
	perror("execve");
	exit(EXIT_SUCCESS);
}
