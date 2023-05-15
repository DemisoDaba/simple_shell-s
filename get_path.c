#include "shell.h"

/**
 * Retrieves the value of the PATH environment variable from the given environment variable array.
 *
 * @param envp   An array of strings representing the environment variables.
 * @return       A pointer to the value of the PATH variable, or NULL if the PATH variable is not found.
 */

char *get_path(char **envp)
{
	char *path = NULL;
	int count;

	if (envp == NULL)
	{
		perror("envp failed to provide PATH");
		return (NULL);
	}
	else
	{
		for(count = 0; envp[count] != NULL; count++)
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
