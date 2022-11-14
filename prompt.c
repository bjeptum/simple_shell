#include <stdio.h>
#include <stdlib.h>

int main(__attribute__((unused))int argc, __attribute__((unused)) char **argv)
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
