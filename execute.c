#include "main.h"

/**
 * execute - Forks a child process and executes a new process
 * @args: user input array arguments
 * Return:  0 or 1 according file program execution
 */
int execute(char **args)
{
	pid_t child_pid;
	int exit_status;

	child_pid = fork();
	if (child_pid < 0)
		exit(1);
	else if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			exit(127);
	}
	else
	{
		wait(&exit_status);
		if (WIFEXITED(exit_status) && exit_status != 0)
			exit(WEXITSTATUS(exit_status));
	}
	return (0);
}
