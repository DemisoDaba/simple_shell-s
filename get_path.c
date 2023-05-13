#include "shell.h"

/**
 * get_path - retrieves the value of the PATH environment variable
 * @envp: the array of strings that contains the environment variables
 *
 * Return: a pointer to the value of the PATH environment variable,
 * or NULL if it is not found
 */

char *get_path(char **envp)
{
	char *path;
	int count;

	if (envp == NULL)
	{
		perror("envp failed to provide PATH");
		return (NULL);
	}
	else
	{
		for (count = 0; envp[count] != NULL; count++)
		{
			if ((stringcmp(envp[count], "PATH=", 4)) == 0)
			{
				path = envp[count] + 5;
				return (path);
			}
		}
	}
	return (NULL);
}
