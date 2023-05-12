#include "shell.h"

/**
 * stringcmp - Compare two strings similar to strcmp
 * @stringA: The first string to be compared
 * @stringB: The second string to be compared
 *
 * Return: 0 if stringA and stringB are exactly equal,
 *         positive value if stringA is greater,
 *         negative value if stringB is greater.
 */

int stringcmp(char *stringA, char *stringB, int a)
{
	int count;
	
	for (count = 0; (count < a) && (stringA[count] != '\0') && (stringB[count] != '\0'); count++)
	{
		if (stringA[count] != stringB[count])
		return (stringA[count] - stringB[count]);
	}
	if ((stringA[count] == '\0') && (stringB[count] == '\0'))
	{
		return (0);
	}
	else
	{
		return (stringA[count] - stringB[count]);
	}
}

