#include "shell.h"
#include "commands.c"
/**
 * main - check whether shell is in interactive or
 * non-interactive mode
 * @argc: total number of arguments passed
 * @argv: array of pointers to the argument strings
 *
 * Return: -1 on failure
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *cmd;

	if (isatty(STDIN_FILENO))
	{
		/* Interactive mode */
		while (1)
		{
			print_prompt();
			cmd = read_cmd();

			if (!cmd)
				break; /* End of file */
			execute_cmd(cmd);
			free(cmd);
		}
	}
	else
	{
		/* Non-Interactive mode */
		cmd = read_cmd();

		if (!cmd)
			return (-1);
		execute_cmd(cmd);
		free(cmd);
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
 * Return: string containing the command
 */
char *read_cmd(void)
{
	size_t len;
	size_t bufsize = 0;
	char *cmd = NULL;

	if (getline(&cmd, &bufsize, stdin) == -1)
	{
		free(cmd);
		return (NULL); /*(Ctrl+D)*/
	}
	/* Remove newline character at the end */
	len = strlen(cmd);

	if (len > 0 && cmd[len - 1] == '\n')
		cmd[len - 1] = '\0';
	return (cmd);
}
