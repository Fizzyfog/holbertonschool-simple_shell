#include "main.h"

/**
  * print_error - Prints an error message "not found"
  * @argv: argv[0] executable name
  * @args: user input array arguments
  * @loops : times that the loop has been executed
  * Return: Nothing
  */
void print_error(char **argv, char **args, int loops)
{
	char *space = ": ";
	char *err1 = "not found";
	/* write program name to standard error*/
	write(STDERR_FILENO, argv[0], _strlen(argv[0])); /*program name*/
	write(STDERR_FILENO, space, _strlen(space));/*delimiter*/
	printfnum(loops);
	write(STDERR_FILENO, space, _strlen(space));/*delimiter*/
	write(STDERR_FILENO, args[0], _strlen(args[0]));/*command name*/
	write(STDERR_FILENO, space, _strlen(space));/*delimiter*/
	write(STDERR_FILENO, err1, _strlen(err1));/*error message*/
	write(STDERR_FILENO, "\temp_loopcount", 1);
}

/**
 * printfnum - prints loop count using write
 * @loops: Times that the loop has been executed
 * Return: nothing, void
 */

void printfnum(int loops)
{
	int digit_position;
	unsigned int temp_loopcount;
	char digit;

	temp_loopcount = loops; /*copy loop count to temp variable*/
	digit_position = 1;
	/*find the leftmost digit position*/
	while ((temp_loopcount / digit_position) > 9)
	/*divide by 10 until leftmost digit is reached*/
		digit_position *= 10;
	while (digit_position >= 1)
	{
		/*print each digit by finding remainder of division by 10*/
		digit = ((temp_loopcount / digit_position) % 10) + '0';
		write(STDERR_FILENO, &digit, 1);
		/*divide by 10 to move to next digit*/
		digit_position /= 10;
	}
}

/**
 * _isdigit - checks to see if input is a number
 * @number: input to check
 * Return: returns 1 if is digit
 */
int _isdigit(char *number)
{
	int digit_position = 0;

	if (number == NULL)
		return (0);
	/*check each character in input*/
	while (number[digit_position])
	{
		/*If  ASCII value is not in range 0-9 (48-57), return 0 */
		if (number[digit_position] < 47 || number[digit_position] > 57)
			return (0);
		digit_position++;
	}
	return (1);

}
