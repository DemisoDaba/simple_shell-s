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

#ifndef shell_h
#define shell_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#define BUFFER_SIZE 1024

int stringcmp(char *StringA, char *StringB, int a);
char *get_user_input();
char **tokenize(char *user_input, char *delimiter);
int stringlen(char *String);
void print(char *String);
char *get_path(char **envp);
int full_length(char **StringsA, char **StringsB);
char *stringdup(char *StringToDup);
char *stringcat(char *CompleteString, char *StringToAdd);
char **full_path(char **tok_path, char **tok_user_input);
char **init_envp(char **envp);
char *stringcpy(char *StringDest, char *StringSource);

#endif /* End of shell_h */
