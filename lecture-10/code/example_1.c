#include <stdio.h>
#include <pthread.h> // we're using threads!

void *print_even(void *arg)
{
  for (int i = 0; i < 10000; i++)
    if (i % 2 == 0)
      printf("Even thread: %d\n", i);
}

void *print_odd(void *arg)
{
  for (int i = 0; i < 10000; i++)
    if (i % 2 != 0)
      printf("Odd thread: %d\n", i);
}

int main(int argc, char *argv[])
{
  pthread_t even, odd; // two pthread_t
  if (pthread_create(&even, NULL, print_even, (void *) 0)) {
    printf("Error creating even thread\n");
  }
  if (pthread_create(&odd, NULL, print_odd, (void *) 0)) {
    printf("Error creating even thread\n");
  }

  // After creating a thread, it's up to the OS to schedule it
  // Specifically, it's the OS scheduler

  // wait for both threads!
  pthread_join(even, NULL);
  pthread_join(odd, NULL);
  printf("Main all done!\n");
}
