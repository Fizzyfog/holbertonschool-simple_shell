#include "main.h"

/**
 * _strlen - Calculates the length of a string
 * @str: string to be measured
 * Return: length of string
 */

int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}

/**
 * _strcmp - Compares the value of chars in two different strings 1 by 1
 * @s1: first string
 * @s2: second string
 * Return: difference between the value in the strings
 */

int _strcmp(char *s1, char *s2)
{
	int char_idx = 0;

	while ((s1[char_idx] != '\0' && s2[char_idx] != '\0') &&
		s1[char_idx] == s2[char_idx])
	{
		char_idx++;
	}
	return (s1[char_idx] - s2[char_idx]);
}

/**
 * *_strncmp - Compares two strings up to n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 * Return: 0 if both strings are equal, a n or -n if they are not
 */

int _strncmp(char *s1, char *s2, int n)
{
	int difference = 0, index = 0;

	while ((s1[index] != '\0' && s2[index] != '\0') && index < n)
	{
		difference = s1[index] - s2[index];
		if (difference != 0)
			break;
		index++;
	}
	return (difference);
}

/**
 * *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to duplicate
 * Return: pointer to a new string which is a duplicate of the string,
 * NULL if str = NULL, NULL if insufficient memory was available
 */

char *_strdup(char *str)
{
	int index, length;
	char *new_string;

	length = _strlen(str);

	new_string = malloc((length + 1) * sizeof(char));

	if (new_string == NULL)
		return (NULL);

	for (index = 0 ; index < length ; index++)
	{
		new_string[index] = str[index];
	}
	new_string[index] = '\0';

	return (new_string);
}

/**
  * _atoi - function that convert a string to an integer
  * @s: string to convert
  * Return: number
  */

int _atoi(char *s)
{
	int index, sign;
	unsigned int number;

	index = number = 0;
	sign = 1;
	for (; (!(s[index] >= 48 && s[index] <= 57)) && s[index] != '\0'; index++)
	{
		if (s[index] == 45)
			sign = sign * -1;

	}
	if (s[index] == '\0')
		return (number);
	for (; (s[index] >= 48 && s[index] <= 57) && s[index] != '\0'; index++)
	{
		number = (number * 10) + (s[index] - 48);
	}
	return (number * sign);
}
