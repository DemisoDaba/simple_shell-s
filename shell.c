#include "shell.h"


int main(int argc, char **argv, char **envp)
{
	int CountA, CountB;
	char *Input;
	char **TokUserInput;
	char **FullPath;
	char *Path = get_path(envp);
	char **TokPath = tokenize(Path, ":\n");
	pid_t PID;
	(void) argc, (void) argv, (void) envp;
	for (;;)
	{
		print(" ($) ");
		Input = get_user_input();
		TokUserInput = tokenize(Input, " \n");
		if (TokUserInput[0] == NULL)
		TokUserInput[0] = " \n";
		FullPath = full(TokPath, TokUserInput[0]);
		CountB = half_len(FullPath);
		for (CountA = 0; (CountA < CountB) && access(FullPath[CountA], X_OK) != 0; CountA++)
		{}
		if (access(FullPath[CountA], X_OK) == 0)
		{
		PID = fork();
		if (PID == 0)
		{
			execve(FullPath[CountA], TokUserInput, envp);
		}
		else if (PID > 0)
		{
			wait(NULL);
		}
		}
		else
		{
			if (stringcmp(TokUserInput[0], "exit", 3) == 0)
			{
				exit(EXIT_SUCCESS);
			}
			print(TokUserInput[0]);
			print(":");
			print(" ");
			print("command not found\n");
			if (stringcmp(TokUserInput[0], "env", 2) == 0)
			{
				for (CountA = 0; envp[CountA] != NULL; CountA++)
				{
					print(envp[CountA]);
				}
			}
		}
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
	return (0);
}
