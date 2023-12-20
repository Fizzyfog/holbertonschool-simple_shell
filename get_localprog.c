#include "main.h"

/**
 * exec_local_program - Execute local programs, redirect simple commands.
 * @args: user input array arguments
 * Return: 0 on success, 1 on failure
 */
int exec_local_program(char **args)
{
	struct stat file_status;

	if (stat(args[0], &file_status) == 0 && access(args[0], X_OK) == 0)
	{
		execute(args);
		return (0);

	}
	get_filepath(args);

	if (stat(args[0], &file_status) == -1)
		return (-1);

	return (execute(args));
}

/**
  * search_dir - Searches in the PATH directory and append the file program to
  * the path according status return
  * @directories: pointer array to all the directories in the PATH
  * @args: user input array arguments
  * Return: 0 on success, -1 on failure
  */
int search_dir(char **directories, char **args)
{
	char *cwd;
	int i;
	struct stat file_status;

	cwd = getcwd(NULL, 0);

	for (i = 0; directories[i] != NULL; i++)
	{
		chdir(directories[i]);
		if (stat(args[0], &file_status) == 0)
		{
			args[0] = path_append(directories[i], args[0]);
			if (args[0] == NULL)
			{
				free_memory(1, cwd);
				free_memory(2, directories);
				return (-1);
			}
			break;
		}
	}
	chdir(cwd);
	free_memory(1, cwd);
	if (directories[i] == NULL)
	{
		free_memory(2, directories);
		return (-1);
	}
	free_memory(2, directories);
	return (0);
}
