#include "shell.h"

/**
 * stringdup - Duplicates a string.
 * @StringToDup: The string to be duplicated.
 *
 * Return: Pointer to the duplicated string on success, or NULL on failure.
 */

char *stringdup(char *StringToDup)
{
	int length =  1 + (stringlen(StringToDup)), count;
	char *DupString = malloc(length * sizeof(char));

	if (DupString == NULL)
	{
		perror("Malloc() failed to allocate memory to duplicate string");
		return (DupString);
	}
	else
	{
		for (count = 0; StringToDup[count] != '\0'; count++)
		{
			DupString[count] = StringToDup[count];
		}
	}
	DupString[count] = '\0';
	return (DupString);
}
