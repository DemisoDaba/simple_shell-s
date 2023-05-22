#include "shell.h"

/**
 * stringcpy - Copy the contents of one string to another.
 *
 * @StringDest: Pointer to the destination string.
 * @StringSource: Pointer to the source string.
 *
 * Return: Pointer to the destination string.
 */

char *stringcpy(char *StringDest, char *StringSource)
{
	int CountA;

	for (CountA = 0; StringSource[CountA] != '\0'; CountA++)
	{
		StringDest[CountA] = StringSource[CountA];
	}
	StringDest[CountA] = '\0';
	return (StringDest);
}

