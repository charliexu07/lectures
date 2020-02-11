#include <pthread.h>
#include <stdio.h>

int sum = 0;

void *do_work(void *arg)
{
  for (int i = 0; i < 1000; i++) {
    // grab a lock here
    sum++;
    // release lock here
  }
}


int main()
{
  pthread_t p1, p2;

  pthread_create(&p1, NULL, do_work, NULL);
  pthread_create(&p2, NULL, do_work, NULL);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);

  printf("Value of sum: %d\n", sum);
}
