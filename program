#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void Program_Execute(char *program_name, char **args) {
  pid_t pid = fork();

  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    // Child process

    // Execute the program using PATH
    execvp(program_name, args);

    // If execvp returns, an error occurred
    perror("execvp");
    exit(EXIT_FAILURE);
  } else {
    // Parent process

    // Wait for the child to finish
    int status;
    if (wait(&status) == -1) {
      perror("wait");
      exit(EXIT_FAILURE);
    }
  }
}

int main(int argc, char **argv, char **envp) {
  char *program_name = "ls";
  char *args[] = {"ls", "-l", NULL};

  Program_Execute(program_name, args);

  return 0;
}
