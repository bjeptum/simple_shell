#include "shell.h"
/**
 * main - checkshell if interactive/ non-interactive
 * @argc: total number of arguments passed
 * @argv: array of pointers to the argument strings
 *
 * Return: -1 on failure
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *cmd;
	ssize_t bytes_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			/* Interactive mode */
			print_prompt();
		}
		bytes_read = read_cmd(&cmd);
		if (bytes_read == -1)
		{
			break; /* End of file */
		}
		if (bytes_read == 0)
			continue;
		if (!execute_builtin(cmd))
		{
			execute_cmd(cmd);
		}

		free_cmd(cmd);
	}
	return (0);
}

/**
 * print_prompt - prints the prompt when shell is in interactive mode
 *
 * Return: void
 */
void print_prompt(void)
{
	char prompt[] = "$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * read_cmd - reads the command inputted by user
 * @cmd: pointer to store the command
 * Return: number of bytes read or -1 on failure
 */
ssize_t read_cmd(char **cmd)
{
	size_t len;
	size_t bufsize = 0;
	ssize_t bytes_read;
	*cmd = NULL;

	bytes_read = getline(cmd, &bufsize, stdin);
	if (bytes_read == -1)
	{
		free(*cmd);
		return (-1); /*(Ctrl+D)*/
	}
	/* Remove newline character at the end */
	len = strlen(*cmd);

	if (len > 0 && (*cmd)[len - 1] == '\n')
		(*cmd)[len - 1] = '\0';
	return (bytes_read);
}

/**
 * free_cmd - free memory allocated by getline
 * @cmd: command executed
 * Return: 0 on success
 */
void free_cmd(char *cmd)
{
	free(cmd);
}
