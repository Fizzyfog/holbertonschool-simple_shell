#include "main.h"

/**
 * get_tokens - Breaks input into a series of tokens using a string
 * delimiter and store them in an array of strings
 * @buffer: getline malloc'd user input
 * Return: A pointer to an array of strings
 */

char **get_tokens(char *buffer)
{
	char **token_list = malloc(sizeof(char *) * countarg(buffer));
	char *token;
	int buffer_index = 0;

	if (buffer == NULL || token_list == NULL)
	{
		free_memory(2, token_list);
		return (NULL);
	}
	token = strtok(buffer, DELIMITER);

	while (token != NULL)
	{
		token_list[buffer_index] = _strdup(token);

		if (token_list[buffer_index] == NULL)
		{
			free_memory(2, token_list);
			return (NULL);
		}

		token = strtok(NULL, DELIMITER);

		buffer_index++;
	}

	token_list[buffer_index] = token;

	return (token_list);
}

/**
 * countarg - Counts the number of user input array arguments
 * @buffer: getline malloc'd user input
 * Return: number of arguments
 */
int countarg(char *buffer)
{
	int buffer_index, count, flag, delimiter_idx;
	char *delimiter = " :";

	flag = buffer_index = 0;
	count = 1;
	if (buffer == NULL)
		return (count);
	while (buffer[buffer_index] != '\0')
	{
		for (delimiter_idx = 0; delimiter[delimiter_idx] != '\0'; delimiter_idx++)
		{
			if (buffer[buffer_index] == delimiter[delimiter_idx] && flag == 0)
			{
				count++;
				flag = 1;
				break;
			}
		}
		if (delimiter[delimiter_idx] == '\0')
			flag = 0;
		buffer_index++;
	}
	return (count + 1);
}
