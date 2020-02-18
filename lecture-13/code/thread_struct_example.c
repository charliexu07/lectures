#include <pthread.h>
#include <stdio.h>

// Example code showing how to pass a structure to a thread function

typedef struct
{
  int x, y, z;
} thread_args;

void *thread_func(void *args)
{
  thread_args *arg = (thread_args*)args;
  printf("Values in thread_func: %d, %d, %d\n", arg->x, arg->y, arg->z);
  pthread_exit(NULL);
}

void do_something(int x, int y, int z)
{
  printf("Values in do something: %d, %d, %d\n", x, y, z);
}

int main(int argc, char *argv[])
{
  // Option 1: call do_something directly
  do_something(0, 1, 2);

  // Option 2: thread-ify it
  pthread_t thread;
  thread_args args = { .x = 0, .y = 1, .z = 2 };
  pthread_create(&thread, NULL, thread_func, (void*)&args);
  pthread_exit(NULL);
}
