#include <stdio.h>
#include <pthread.h> // we're using threads!

void *print_nums(void *arg)
{
  // Assume that arg points to an int
  // If arg == 0 we are even
  // Else we are odd
  if (*((int*)arg) == 0) {
    for (int i = 0; i < 10000; i++)
      if (i % 2 == 0)
        printf("Even thread: %d\n", i);
  } else {
    for (int i = 0; i < 10000; i++)
      if (i % 2 != 0)
        printf("Odd thread: %d\n", i);
  }
}

int main(int argc, char *argv[])
{
  int *arg = malloc(sizeof(int));
  *arg = 0; // initially kick off the even

  pthread_t even, odd; // two pthread_t
  if (pthread_create(&even, NULL, print_nums, (void *)arg)) {
    printf("Error creating even thread\n");
  }
  *arg = 1;
  if (pthread_create(&odd, NULL, print_nums, (void *)arg)) {
    printf("Error creating odd thread\n");
  }

  // After creating a thread, it's up to the OS to schedule it
  // Specifically, it's the OS scheduler

  // wait for both threads!
  pthread_join(even, NULL);
  pthread_join(odd, NULL);
  printf("Main all done!\n");
  free(arg); // free when we're done!
}
