#include "main.h"

/**
 * _getenv - Search in environment variable to find a specific variable name
 * @name: environment variable
 * Return: pointer to the corresponding value string
 */
char *_getenv(char *name)
{
	int index = 0;
	/* loop through each environment variable */
	while (environ[index])
	{
		/* compare the name of the variable with the name passed */
		if (_strncmp(environ[index], name, _strlen(name)) == 0)
			/* return pointer to value of the variable */
			return (environ[index] + (_strlen(name) + 1));

		++index;
	}
	/* if not found, return NULL */
	return (NULL);
}
