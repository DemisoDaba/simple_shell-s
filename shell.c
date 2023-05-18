#include "shell.h"


int main(int argc, char **argv, char **envp)
{
	int CountA;
	char *Input;
	char **TokUserInput;
	char **FullPath;
	char *Path = get_path(envp);
	char **TokPath = tokenize(Path, ":\n");
	char **arg;
	for (;;)
	{
		print(" ($) ");
		Input = get_user_input();
		TokUserInput = tokenize(Input," \n");
		FullPath = full(TokPath, *TokUserInput);
		args(FullPath, TokUserInput, envp);
	}	
	for (CountA = 0; TokUserInput[CountA] != NULL; CountA++)
	{
		free(TokUserInput[CountA]);
	}
	for (CountA = 0; TokPath[CountA] != NULL; CountA++)
	{
		free(TokPath[CountA]);
	}
	for (CountA = 0; FullPath[CountA] != NULL; CountA++)
	{
		free(FullPath[CountA]);
	}
	free(Input);
	free(TokUserInput);
	free(TokPath);
	free(FullPath);
}	
