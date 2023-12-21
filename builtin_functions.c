#include "main.h"

/**
* exec_builtin - Initializes built-in functions
* @args: user input array arguments
* @buffer: getline malloc'd user input
* @loops : times that the loop has been executed
* Return: 0 on exit, 1 to continue with the program
*/
int exec_builtin(char **args, char *buffer, int loops)
{
	if (_strcmp(args[0], "env") == 0)
	{
		handle_env();
		free_memory(1, buffer), free_memory(2, args);
		return (1);
	}
	else if (_strcmp(buffer, "exit") == 0)
		handle_exit(args, buffer, loops);

	else if (_strcmp(args[0], "cd") == 0)
	{
		handle_cd(args);
		free_memory(1, buffer), free_memory(2, args);
		return (1);
	}
	return (0);
}

/**
* handle_exit - Function that exits the Simple Shell
* @args: user input array arguments
* args[1] is the number to exit
* @buffer: getline malloc'd user input
* @loops : times that the loop has been executed
* Return: Nothing
*/
int handle_exit(char **args, char *buffer, int loops)
{
	int status = 0;

	char err[100];

	if (args[1] != NULL)
	{
		if (_isdigit(args[1]))
		{
			status = _atoi(args[1]);
			if (status > 255) /* Bigger values result to mod 256 */
				status = status % 256;
			if (status < 0)
			{
				sprintf(err, "./hsh: %d: %s: Illegal number %s\n"
					, loops, args[0], args[1]);
				write(STDERR_FILENO, &err, _strlen(err));
				status = 2;
			}
		}
		else
		{
			sprintf(err, "./hsh: %d: %s: Illegal number: %s\n",
				loops, args[0], args[1]);
			write(STDERR_FILENO, &err, _strlen(err));
			status = 2;
		}
	}

	free_memory(1, buffer), free_memory(2, args);
	exit(status);
}

/**
* handle_env - Prints the global environment variable
* Return: Nothing
*/
void handle_env(void)
{
	int index;

	for (index = 0; environ[index] != NULL; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
	};
}


/**
* handle_cd - Changes current working directory according to argument
* @args: user's input arguments as array of strings
* 2nd argument, if present, is the target directory.
* If 2nd argument is NULL or '~', change to the home directory.
* If 2nd argument is '-', change to the previous directory.
* Return: Nothing. If error during directory print error message.
*/
void handle_cd(char **args)
{
	char *home_dir = _getenv("HOME");

	char *previous_dir = _getenv("OLDPWD");
	if ((args[1] == NULL && home_dir) || (args[1][0] == '~' && home_dir))
	{
		chdir(home_dir);
	}
	else if (args[1][0] == '-' && previous_dir)
	{
		chdir(previous_dir);
	}
	else if (chdir(args[1]) != 0)
	{
		perror("hsh");
	}
}

/**
* signal_handle - This program allows ctrl+C to be
* printed and new line with enter is pressed
* @sign: int
* Return: void
*/
void signal_handle(int sign)
{
	if (sign == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
