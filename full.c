#include "shell.h"

char **full(char **TokPath, char *TokUserInput)
{
    int PathCount;
    int CountA;
    char **FullPath;

    for (PathCount = 0; TokPath[PathCount] != NULL; PathCount++)
    {
    }

    FullPath = malloc((PathCount + 1) * sizeof(char *));

    if (FullPath == NULL)
    {
        perror("malloc() failed to allocate memory for FullPath");
        exit(EXIT_FAILURE);
    }

    for (CountA = 0; CountA < PathCount; CountA++)
    {
        int PathLen = stringlen(TokPath[CountA]);
        int Len = (PathLen + stringlen(TokUserInput) + 1);

        FullPath[CountA] = malloc(Len * sizeof(char));

        if (FullPath[CountA] == NULL)
        {
            perror("malloc() failed to allocate memory for FullPath[]");
            exit(EXIT_FAILURE);
        }

        stringcpy(FullPath[CountA], TokPath[CountA]);
        stringcat(FullPath[CountA], "/");
        stringcat(FullPath[CountA], TokUserInput);
        FullPath[CountA][Len] = '\0';
    }

    FullPath[CountA] = NULL;
    return FullPath;
}
