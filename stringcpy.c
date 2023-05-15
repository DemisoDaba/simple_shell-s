#include "shell.h"

/**
 * Copies the contents of one string to another.
 *
 * @param StringDest     Pointer to the destination string where the contents will be copied.
 * @param StringSource   Pointer to the source string whose contents will be copied.
 * @return               Pointer to the destination string.
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
