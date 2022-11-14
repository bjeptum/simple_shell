#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
/**
* main - creates a child process
*
* Return: pid of child in parent
*/
int main(void)
{
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("Unsucessful\n");
		return (1);
	}
	if (pid == 0)
	{
		printf("I'm the child process.\n");
	}
	else
	{
		wait(NULL);
		printf("I'm the parent process; the child got pid %d.\n", pid);
	}
	return (0);
}
