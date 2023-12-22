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
	/* check si 1er argument est env */
	if (_strcmp(args[0], "env") == 0)
	{
		/* execute commande env */
		handle_env();
		/* free mémoire allouée au buffer et arguments*/
		free_memory(1, buffer), free_memory(2, args);
		return (1);
	}
	/* check si buffer contient "exit" */
	else if (_strcmp(buffer, "exit") == 0)
		handle_exit(args, buffer, loops);
	/* check si 1er argument est cd */
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
	int exit_status = 0;
	/* initialise buffer de messages d'erreur */
	char error[100];
	/* check si 2e arg n'est pas NULL */
	if (args[1] != NULL)
	{
		/* check si 2e arg est un nombre */
		if (_isdigit(args[1]))
		{
			/* convertir string en int et l'attribue à exit status */
			exit_status = _atoi(args[1]);
			/* Si stat > 255, %256 le ramène in intervalle 0-255 */
			if (exit_status > 255)
				exit_status = exit_status % 256;
			/* Conditions pour messages erreurs */
			if (exit_status < 0)
			{
				sprintf(error, "./hsh: %d: %s: Illegal number %s\n"
					, loops, args[0], args[1]);
				write(STDERR_FILENO, &error, _strlen(error));
				exit_status = 2;
			}
		}
		else
		{
			sprintf(error, "./hsh: %d: %s: Illegal number: %s\n",
				loops, args[0], args[1]);
			write(STDERR_FILENO, &error, _strlen(error));
			exit_status = 2;
		}
	}

	free_memory(1, buffer), free_memory(2, args);
	exit(exit_status);
}

/**
* handle_env - Prints the global environment variable
* Return: Nothing
*/
void handle_env(void)
{
	int index;
	/* Parcourt chaque variable d'environnement jusqu'à NULL */
	for (index = 0; environ[index] != NULL; index++)
	{
		/* écrit env var sur sortie standard */
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
	char *home_dir = _getenv("HOME"); /* récup répertoire d'acuueil */

	char *previous_dir = _getenv("OLDPWD");
	/* va au rep d'accueil si 2e arg est NULL- ou ~ */
	if ((args[1] == NULL && home_dir) || (args[1][0] == '~' && home_dir))
	{
		chdir(home_dir);
	}
	/* va au rep précédent si 2e arg est - */
	else if (args[1][0] == '-' && previous_dir)
	{
		chdir(previous_dir);
	}
	/* Si changement de répertoire échoue, affiche message d'erreur */
	else if (chdir(args[1]) != 0)
	{
		perror("Error: impossible to change directory");
	}
}

/**
* signal_handle - This program allows ctrl+C to be
* printed and new line when enter is pressed
* @sign: int
* Return: void
*/
void signal_handle(int sign)
/* Vérifie si le signal reçu est SIGINT (généré par ctrl+C) */
{
	if (sign == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
