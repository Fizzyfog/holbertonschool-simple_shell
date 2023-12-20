#include "main.h"

/**
 * main - Creates a loop for to receive user call functions, parse the input
 * and check program type to execute a program file if success
 * @argc: number of command line arguments
 * @argv: command line arguments
 * Return: 0, success, otherwise errors
 */
int main(int argc, char **argv)
{
	char *buffer, **args;
	size_t length;
	int loops = 1;
	(void)argc;

	signal(SIGINT, signal_handle);

	while (1)
	{
		buffer = NULL, args = NULL;
		length = 0;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&buffer, &length, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			return (0);
		}
		args = get_tokens(buffer);
		if (args != NULL && args[0] != NULL)
		{
			if (exec_builtin(args, buffer, loops))
				continue;

			if (exec_local_program(args) == -1)
				print_error(argv, args, loops);
		}
		free_memory(1, buffer);
		free_memory(2, args);
		loops++;
	}
	return (0);
}
