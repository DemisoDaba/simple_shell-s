#include "shell.h"

/**
 * tokenize - Tokenizes a string of user input
 * @user_input: The input string to tokenize
 * @separator: The separator used for tokenization
 *
 * This function takes a string of user input and tokenizes it
 * It returns a double pointer to an array of tokens, or NULL on failure.
 *
 * Return: A double pointer to an array of tokens, or NULL on failure
 */

char **tokenize(char *user_input, char *separator)
{
	int tokenCount = 0, MaxNumOfTok = BUFFER_SIZE;
	char *currentToken = NULL;
	char **tokenArray = malloc(sizeof(char *) * MaxNumOfTok);

	if (tokenArray == NULL)
	{
		perror("Malloc failed to allocate memory for storing tokens");
		return (NULL);
	}
	else
	{
		currentToken = strtok(user_input, separator);

		if (currentToken == NULL)
		{
			perror("Strtok failed to tokenize user input");
			return (tokenArray);
		}
		else
		{

			while (currentToken != NULL)
			{
				if (tokenCount == MaxNumOfTok)
				{
					MaxNumOfTok = MaxNumOfTok * 2;
					tokenArray = realloc(tokenArray, MaxNumOfTok * sizeof(char *));
					if (tokenArray == NULL)
					{
					perror("Realloc failed to reallocate memory for storing token");
					free(tokenArray);
					return (NULL);
					}
				}
				tokenArray[tokenCount++] = currentToken;
				currentToken = strtok(NULL, separator);
			}
		}
	}
	return (tokenArray);
}
