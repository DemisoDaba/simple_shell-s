#include "shell.h"

/**
 * stringcat - Concatenates two strings
 * @CompleteString: The string to which @StringToAdd will be appended
 * @StringToAdd: The string to be appended to @CompleteString
 *
 * Return: A pointer to the concatenated string on success, NULL on failure
 */

char *stringcat(char *CompleteString, char *StringToAdd)
{
	int countA, countB;

	int length = (stringlen(CompleteString) + stringlen(StringToAdd));

	char *FullString = malloc((length + 1) * sizeof(char));

	if (FullString == NULL)
	{
		perror("Malloc() failed to allocate memory to concatenate strings");
		return (NULL);
	}

	for (countA = 0; CompleteString[countA] != '\0'; countA++)
	{
		FullString[countA] = CompleteString[countA];
	}
	for (countB = 0; StringToAdd[countB] != '\0'; countB++)
	{
		FullString[countA++] = StringToAdd[countB];
	}
	FullString[countA] = '\0';
	return (FullString);
}
