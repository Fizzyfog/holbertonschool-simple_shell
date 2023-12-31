#include "main.h"

/**
  * free_memory - Frees malloc'd spaces based on what number is passed
  * @n: free a single pointer n(1) or double pointer n(2)
  * Return: Nothing
  */
void free_memory(int n, ...)
{
	char **ptr2, *ptr1;
	va_list valist;
	int index;

	va_start(valist, n);

	if (n == 1)
	{
		ptr1 = va_arg(valist, char *);
		if (ptr1 == NULL)
			return;
		free(ptr1);
	}
	if (n == 2)
	{
		ptr2 = va_arg(valist, char **);
		if (ptr2 == NULL)
			return;
		for (index = 0; ptr2[index] != NULL; index++)
			free(ptr2[index]);
		free(ptr2);
	}

	va_end(valist);
}
