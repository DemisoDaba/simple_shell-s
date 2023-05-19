#ifndef shell_h
#define shell_h

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024

void args(char **FullPath, char **TokUserInput, char **envp);
char *stringcat(char *CompleteString, char *StringToAdd);
char **full_path(char **tok_path, char **tok_user_input);
char *stringcpy(char *StringDest, char *StringSource);
char **tokenize(char *user_input, char *delimiter);
int stringcmp(char *StringA, char *StringB, int a);
int full_length(char **StringsA, char **StringsB);
char **full(char **TokPath, char *TokUserInput);
char *stringdup(char *StringToDup);
char **init_envp(char **envp);
int stringlen(char *String);
char *get_path(char **envp);
int half_len(char **half);
void print(char *String);
char *get_user_input();
#endif /* End of shell_h */
