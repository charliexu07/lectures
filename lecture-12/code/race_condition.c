#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

volatile int sum = 0;
static int max = 10000;

// initialize lock to unlocked
static int lock = 0;

void get_lock()
{
  // how should we implement this?
  while (lock == 1)
    ;
  lock = 1;
}

void unlock()
{
  lock = 0; // guaranteed to be atomic
}

void *thread_function(void *arg)
{
  // "critical section" uses our mutual exclusion
  for (int i = 0; i < max; i++) {
    get_lock();
    sum++;
    unlock();
  }

  return NULL;
}
                                                                             
int main(int argc, char *argv[])
{                    
    pthread_t p1, p2;
    if (argc != 2) {
	fprintf(stderr, "usage: %s <loopcount>\n", argv[0]);
	exit(1);
    }

    max = atoi(argv[1]);

    // create two threads
    pthread_create(&p1, NULL, thread_function, NULL);
    pthread_create(&p2, NULL, thread_function, NULL);

    // wait for both to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    // print the final value of sum
    printf("Final value of sum: %d\n", sum);
}
