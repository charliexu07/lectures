#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// A program to:
// 1. Create a child process
// 2. Run a new program
// 3. Wait on the child process
// 4. Check how it exited

int main(int argc, char *argv[])
{
  pid_t pid = fork(); // create a new child process
  if (pid > 0) {
    int status = 0;
    if (wait(&status) != -1) {
      if (WIFEXITED(status)) {
	// now check to see what its exit status was
	printf("The exit status was: %d\n", WEXITSTATUS(status));
      } else if (WIFSIGNALED(status)) {
	// it was killed by a signal
	printf("The signal that killed me was %d\n", WTERMSIG(status));
      }
    } else {
      printf("Error waiting!\n");
    }
  } else if (pid == 0) {
    char *args[] = { "ls", "-l", (char *)0 };
    execvp(args[0], args); // one variant of exec
    printf("Will only print if error with execvp.n");
    exit(1);
  } else {
    printf("Error with fork!\n");
  }
}
