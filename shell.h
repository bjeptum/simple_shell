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


/* External variable declaration */
extern char **environ;

/* Functions */
void print_prompt(void);
ssize_t read_cmd(char **cmd);
void execute_cmd(char *cmd);
void free_cmd(char *cmd);
void exit_shell(void);
void print_environment(void);
char *find_executable(char *command);
void execute_cmd(char *cmd);
char **tokenize_command(char *cmd, int *arg_count);
void execute_child(char **args);
int check_builtin(char *cmd);
int execute_builtin(char *cmd);



#endif /* SHELL_H */
