#include "main.h"

/**
  * get_filepath - Searches PATH for a program's file path.
  * Tokenizes PATH into subdirectories, stores them in an array,
  * and checks if the program file path exists in these directories.
  *
  * @args: Array of strings representing user's input arguments.
  * 1st argument is the program to search.
  * Return: 0 if program path is found, -1 if not found or error.
  */
int get_filepath(char **args)
{
	int index = 0;
	char **directories = malloc(sizeof(char *) * BUFFSIZE);
	char *path, *path_var;

	path = _strdup(_getenv("PATH"));

	if (path == NULL || directories == NULL)
	{
		free_memory(1, path);
		return (-1);
	}

	path_var = strtok(path, "=:");

	while (path_var != NULL)
	{
		directories[index] = _strdup(path_var);

		if (directories[index] == NULL)
		{
			free_memory(1, path);
			free_memory(2, directories);
			return (-1);
		}

		path_var = strtok(NULL, "=:");
		index++;
	}

	directories[index] = path_var;

	if (search_dir(directories, args) == -1)
	{
		free_memory(1, path);
		return (-1);
	}

	free_memory(1, path);

	return (0);
}
