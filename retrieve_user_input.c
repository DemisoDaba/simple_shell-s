#include "shell.h"

/**
 * Retrieves user input from stdin and returns it as a dynamically allocated string.
 *
 * @return  A pointer to the user input string, or NULL if memory allocation fails or an error occurs.
 *          The returned string is dynamically allocated and should be freed by the caller when no longer needed.
 */

char *get_user_input()
{
	size_t MAX_USER_INPUT = BUFFER_SIZE;
	ssize_t user_input_length;
	char *user_input = malloc(sizeof(char) * MAX_USER_INPUT);

	if (user_input == NULL)
	{
		return (NULL);
	}
	else
	{
		user_input_length = getline(&user_input, &MAX_USER_INPUT, stdin);
		if (user_input_length == -1)
		{	
			if (errno == EOF)
			{
				perror("exiting.......");
			}
			free(user_input);
			exit (EXIT_SUCCESS);
		}
		if ((user_input[user_input_length - 1] == '\0') || (user_input[user_input_length -1] == '\n'))
		{
			user_input[user_input_length] = '\0';
		}
	}
	return (user_input);
}
