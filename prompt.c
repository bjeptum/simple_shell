#include <stdio.h>
#include <stdlib.h>
/**
* prompt - a program that prints $ and waits  for user input
*
* Return: prompt $
*/
void prompt(void)
{
	size_t len = 0;
	char *line = NULL;
	ssize_t nread;

	printf("$ ");

	nread = getline(&line, &len, stdin);
	printf("%s", line);
	printf("Number of characters: %ld/n", nread);

	free(line);
	exit(EXIT_SUCCESS);
}
