#ifndef shell_h
#define shell_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 1024

int stringcmp(char *stringA, char * stringB);
char *get_user_input();

#endif /* End of shell_h */