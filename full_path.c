#include "shell.h"

/**
 * Constructs an array of full file paths by concatenating the elements of `tok_path`
 * with the elements of `tok_user_input`.
 *
 * @param tok_path         An array of strings representing the path components.
 * @param tok_user_input   An array of strings representing user input components.
 * @return                 A dynamically allocated array of strings representing the full file paths,
 *                         or NULL if memory allocation fails.
 */

char **full_path(char **tok_path, char **tok_user_input)
{
    int path_count = 0;
    int i, j;
    int length;
    int full_path_count;
    int user_input_count = 0;
    char **full_path;

    while (tok_path[path_count] != NULL)
        path_count++;

    while (tok_user_input[user_input_count] != NULL)
        user_input_count++;

    full_path_count = path_count;

    full_path = malloc((full_path_count + 1) * sizeof(char *));

    if (full_path == NULL)
    {
        perror("Malloc() failed to allocate memory for full_path");
        return NULL;
    }
    else
    {
        for (i = 0; i < path_count; i++)
        {
            length = stringlen(tok_path[i]) + 1;

            for (j = 0; j < user_input_count; j++)
            {
                length = length + stringlen(tok_user_input[j]) + 1;
            }

            full_path[i] = malloc(length * sizeof(char));
            if (full_path[i] == NULL)
            {
                perror("Malloc() failed to allocate memory for concatenated string");
                return NULL;
            }

            stringcpy(full_path[i], tok_path[i]);
            stringcat(full_path[i], "/");

            for (j = 0; j < user_input_count; j++)
            {
                stringcat(full_path[i], tok_user_input[j]);
                if (j < user_input_count - 1)
                {
		    
                    stringcat(full_path[i], "");
                }	  
            }
            full_path[i][length - 2] = '\0';
        }
        full_path[full_path_count] = NULL;
        return full_path;
    }
}
