#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
* main - loops through read command and executes
* @argv: count of command-line arguments
* @argc: array of character pointers listing all the arguments
* Return: output of command inputted
*/
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *cmd;

	do {
		prompt();

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
		if (strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}
		printf("%s\n", cmd);

		free(cmd);
	} while (1);

	exit(EXIT_SUCCESS);
}
