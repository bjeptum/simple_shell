#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
* readline: reads an input into the buffer
*
* Return: the line read
*/
char *readline()
{
	char *line = (char *)malloc(sizeof(char) *1024);
	char c;
	int ps = 0, bufsize = 1024;

	if (!line)
	{
		printf("\nBuffer Allocation Error.");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			line[ps] = '\0';
			return (line);
		}
		else
		{
			line[ps] = c;
		}
		ps++;
		/* buffer is exceeded*/
		if (ps >= bufsize)
		{
			bufsize +=1024;
			line = realloc(line, sizeof(char) *bufsize);
			if (!line)
			{
				printf("\nBuffer Allocation Error.");
				exit(EXIT_FAILURE);
			}
		}
	}
}
