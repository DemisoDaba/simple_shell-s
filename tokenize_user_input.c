#include "shell.h"

00
/**
 * tokenizeUserInput - Tokenizes a user input string
 * @userInput: The input string to be tokenized
 *
 * Return: An array of strings representing the tokens, or NULL on failure
 */

char **tok_user_input(char *user_input)
{
	const char *separator = " ";
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
			free(tokenArray);
			return (NULL);
		}
		else
		{

			while (currentToken != NULL)
			{
				if (tokenCount == MaxNumOfTok)
				{
					MaxNumOfTok = MaxNumOfTok * 2;
					tokenArray = realloc(Tokens, MaxNumOfTok * sizeof(char *));
					if (tokenArray == NULL)
					{
					perror("Realloc failed to reallocate memory for storing token");
					free(tokenArray);
					return (NULL);
					}
				}
				Tokens[tokenCount++] = currentToken;
				currentToken = strtok(NULL, separator);
			}
		}
	}
	return (tokenArray);
}
