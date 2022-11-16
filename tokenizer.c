#include "shell.h"

/**
 * tokenize - splits a string into an array of tokens
 * @str: string to be tokenized and packaged
 *
 * Return: vector array of string tokens
 */

char **tokenize(char *str)
{
	size_t index = 0, io = 0;
	int tkn = 1;
	char **tokens = NULL;
	char *buf = NULL, *token = NULL, *bufptr = NULL, *delim = " :\t\r\n";

	buf = duplicate_str(str);
	if (buf == NULL)
		return (NULL);
	bufptr = buf;

	while (*bufptr)
	{
		if (check_str(delim, *bufptr) != NULL && io == 0)
		{
			tkn++;
			io = 1;
		}
		else if (check_str(delim, *bufptr) == NULL && io == 1)
			io = 0;
		bufptr++;
	}
	tokens = malloc(sizeof(char *) * (tkn + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = duplicate_str(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = NULL;

	free(buf);
	return (tokens);
}

