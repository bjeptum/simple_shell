#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
/**
* min - allows a process to execute another program
*
*
*/
int main (int argc, char *argv[])
{
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
