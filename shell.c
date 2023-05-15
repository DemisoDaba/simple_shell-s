#include "shell.h"

int main(int argc, char **argv, char **envp)
{
	char *path = get_path(envp);
	char **tok_path = tokenize(path, ":");
	char *input;
	char **token;
	char **FullPath;
	int count, CountB, CountC;
	(void) argc, (void) argv;
	while(true)
	{
		print("($) ");
		input = get_user_input();
		token = tokenize(input, " ");
		FullPath = full_path(tok_path, token);
		for (count = 0; FullPath[count] != NULL; count++)
		{
			printf("%s", FullPath[count]);
		}
	}
	free(path);
	free(tok_path);
	free(token);
	free(FullPath);
	return (0);
}
