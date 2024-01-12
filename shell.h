#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


/* Functions */
void print_prompt(void);
char *read_cmd(void);
void execute_cmd(char *cmd);
void free_cmd(char *cmd);



#endif /* SHELL_H */
