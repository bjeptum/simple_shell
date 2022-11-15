#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
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
/**
* splitline - breaks a line into tokens
* @line: line to be splitted
*
* Return: tokens (Abstract syntax Tree)
*/
char **splitline(char *line)
{
	char **tokens = (char **)malloc(sizeof(char *) * 64);
	const char *token;
	char delim[10] = "\t\n\r\a";
	int ps = 0, bufsize = 64;

	if (!tokens)
	{
		printf("\nBuffer Allocation Error.");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	while (token != NULL)
	{
		token[ps] = token;
		ps++;
		if (ps >= bufsize)
		{
			bufsize += 64;
			line = realloc(line, bufsize * sizeof(char *));
			if (!line)
			{
				printf("\nBuffer Allocation Error.");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	token[ps] = NULL;
	return (tokens);
}
