#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

static int arr[100000];
static int total_sum = 0;

// compute the sum of the first 50000 elements
void *compute_sum_one(void *arg)
{  
  // retrieve value of arg
  int val = *((int*)arg);
  printf("Value of arg in sum one: %d\n", val);

  int sum = 0;
  for (int i = 0; i < 50000; i++) {
    //printf("Thread 1 at element: %d\n", i);
    sum += arr[i];
  }

  printf("Thread one sum = %d\n", sum);

  // The line below introduces a subtle race condition!
  total_sum += sum;
}

// compute the sum of the second 50000 elements
void *compute_sum_two(void *arg)
{  
  int sum = 0;
  for (int i = 50000; i < 100000; i++) {
    //printf("Thread 2 at element: %d\n", i);
    sum += arr[i];
  }

  // This sum overflows because the sum gets too big!
  printf("Thread two sum = %d\n", sum);
  total_sum += sum;
}

int main(int argc, char *argv[])
{
  // initialize array
  for (int i = 0; i < 100000; i++)
    arr[i] = i;

  // two threads
  pthread_t one, two;

  // allocate memory on heap to pass to thread one
  int *val = malloc(sizeof(int));
  *val = 31;
  
  // create two threads and let them go!
  if (pthread_create(&one, NULL, compute_sum_one, (void *) val)) {
    printf("Error with pthread create!\n");
    exit(1);
  }
  if (pthread_create(&two, NULL, compute_sum_two, (void *) 0)) {
    exit(1);
  }

  // wait for the two threads to finish
  pthread_join(one, NULL);
  pthread_join(two, NULL);
 
  printf("Total sum: %d\n", total_sum);
}
