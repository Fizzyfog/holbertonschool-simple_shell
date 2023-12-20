#ifndef MAIN_H
#define MAIN_H

#define BUFFSIZE 64
#define DELIMITER " \t\r\n\a"
#define  _GNU_SOURCE

#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* global environment variables */
extern char **environ;

/* execution functions */
int exec_local_program(char **args);
int exec_builtin(char **args, char *buffer, int loops);
int search_dir(char **command, char **args);
int execute(char **args);

/* simple shell handling functions */
void signal_handle(int sign);
void free_memory(int n, ...);
void print_error(char **argv, char **args, int loops);
int countarg(char *buffer);
char **get_tokens(char *buffer);
void printfnum(int num);
int _atoi(char *arg);
int _isdigit(char *number);

/* string handling functions */
int _strlen(char *str);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/* path and search handling functions */
char *path_append(char *path, char *command);
char *_getenv(char *name);
int get_filepath(char **args);

/* built-in functions */
void handle_env(void);
int handle_exit(char **args, char *buffer, int loops);
void handle_cd(char **args);

#endif /* MAIN_H */
