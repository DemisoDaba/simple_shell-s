#ifndef shell_h
#define shell_h

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 1024

int stringcmp(char *stringA, char *stringB, int a);
char **tokenize(char *user_input, char *separator);
int stringlen(char *string);
char *get_path(char **envp);
void print(char *string);
char *get_user_input();
#endif /* End of shell_h */
