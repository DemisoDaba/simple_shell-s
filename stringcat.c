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
	int CountA, CountB;

	for (CountA = 0; CompleteString[CountA] != '\0'; CountA++)
	{
	}

	for (CountB = 0; StringToAdd[CountB] != '\0'; CountB++)
	{
		CompleteString[CountA++] = StringToAdd[CountB];
	}
	CompleteString[CountA] = '\0';
	return (CompleteString);
}
