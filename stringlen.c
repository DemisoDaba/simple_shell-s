#include "shell.h"
000
/**
 * stringlen - Calculate the length of a string
 * @string: The string to calculate the length of
 *
 * Return: Length of the string, or -1 on error
 */


int stringlen(char *string)
{
	int count = 0;

	if (string == NULL)
	{
		perror("Error: Empty string encountered while calculating its length");
		return (count - 1);
	}
	else
	{
		for (count = 0; string[count] != '\0'; count++)
		{	}
	return (count);
	}
}
