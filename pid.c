#include <stdio.h>
#include <unistd.h>
/**
* main - get pid and ppid
*
* Return: Always 0
*/
int main(void)
{
	int p_id, p_pid;

	p_id = getpid(); /*process id*/
	p_pid = getppid(); /*parent process id*/

	printf("Process ID: %d\n", p_id);
	printf("Parent Process ID: %d\n", p_pid);

	return (0);
}
