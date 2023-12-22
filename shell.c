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
	/* handle Ctrl+C interruption */
	signal(SIGINT, signal_handle);

	while (1)
	{
		buffer = NULL, args = NULL;
		length = 0;
		/* print prompt if shell is from a terminal */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&buffer, &length, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			return (0);
		}
		args = get_tokens(buffer); /*tokenize input*/
		if (args != NULL && args[0] != NULL)
		{
			if (exec_builtin(args, buffer, loops)) /*check if builtin command*/
				continue;

			if (exec_local_program(args) == -1) /*check if local program*/
				print_error(argv, args, loops); /*print error if fail*/
		}
		free_memory(1, buffer);
		free_memory(2, args);
		loops++;
	}
	return (0); /* exit shell on success */
}
