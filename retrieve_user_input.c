#include "shell.h"

/**
 * get_user_input - Reads a line of input from the user
 *
 * Return: Pointer to the user input string, or NULL on failure
 */

char *get_user_input()
{
	size_t MAXIMUM_USER_INPUT = BUFFER_SIZE;
	ssize_t user_input_length;
	char *user_input = malloc(sizeof(char) * MAXIMUM_USER_INPUT);

	if (user_input == NULL)
	{
		return (NULL);
	}
	else
	{
		user_input_length = getline(&user_input, &MAXIMUM_USER_INPUT, stdin);
		if (user_input_length == -1)
		{
			free(user_input);
			return (NULL);
			if ((user_input[(user_input_length - 1)] == '\0') ||
			(user_input[user_input_length - 1] == EOF))
			user_input[(user_input_length - 1)] = '\0';
		}
	}
	return (user_input);
}

