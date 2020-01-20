#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// A very simple program to start a new process and run a program

int main(int argc, char *argv[])
{
  pid_t pid = fork();
  if (pid > 0) {
    // parent
  } else if (pid == 0) {
    char *args[] = { "ls", "-l", (char *)0 };
    execvp(args[0], args);
    printf("Will only print if error with execvp.n");
    exit(1);
  } else {
    printf("Error with fork!\n");
  }
}
