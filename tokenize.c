#include "shell.h"

/**
 * tokenize - Tokenizes a string of user input
 * @user_input: The input string to tokenize
 * @delimiter: The separator used for tokenization
 *
 * This function takes a string of user input and tokenizes it
 * It returns a double pointer to an array of tokens, or NULL on failure.
 *
 * Return: A double pointer to an array of tokens, or NULL on failure
 */

char **tokenize(char *user_input, char *delimiter)
{
    int NumOfTok = 0, MaxNumOfTok = BUFFER_SIZE;
    char *Token = NULL;
    char **Tokens = malloc(sizeof(char *) * (MaxNumOfTok + 1));

    if (Tokens == NULL)
    {
        perror("Malloc failed to allocate memory for storing tokens");
        return NULL;
    }
    else
    {
        Token = strtok(user_input, delimiter);

        if (Token == NULL)
        {
            perror("Strtok failed to tokenize user input");
        }
        else
        {
            while (Token != NULL)
            {
                if (NumOfTok == MaxNumOfTok)
                {
                    MaxNumOfTok = MaxNumOfTok * 2;
                    Tokens = realloc(Tokens, (MaxNumOfTok + 1) * sizeof(char *));
                    if (Tokens == NULL)
                    {
                        perror("Realloc failed to reallocate memory for storing token");
                        free(Tokens);
                        return (NULL);
                    }
                }
                Tokens[NumOfTok] = malloc(stringlen(Token));  // Allocate memory for token
                if (Tokens[NumOfTok] == NULL)
                {
                    perror("Malloc failed to allocate memory for token");
                    free(Tokens);
                    return NULL;
                }
                stringcpy(Tokens[NumOfTok], Token);  // Copy token contents
                NumOfTok++;
                Token = strtok(NULL, delimiter);
            }
        }
    }
    Tokens[NumOfTok] = NULL;  // Set the last element of Tokens to NULL
    return Tokens;
}

