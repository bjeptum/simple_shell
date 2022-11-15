#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
/**
* main - allows a process to execute another program
*
*
*/
int main (void)
{
	int argc = 0;
	char *argv[] = {NULL, "Main", "program", NULL};
	char *newArgv[] = { NULL, "Main", "program", "started", NULL};
	char *newEnvp[] = { NULL};

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	newArgv[0] = argv[1];

	execve(argv[1], newArgv, newEnvp);
	perror("execve");
	exit(EXIT_SUCCESS);
}
