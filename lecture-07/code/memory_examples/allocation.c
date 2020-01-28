// example that can demonstrate how the OS allocates memory on demand

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1000000

char *arr = 0; // arr points to an array of chars

void allocate_space()
{
  arr = malloc(SIZE * sizeof(char));
  if (!arr) {
    printf("Couldn't allocate space!\n");
    exit(1);
  }
}

void use_space()
{
  for (int i = 0; i < SIZE; i++) {
    *(arr + i) = 'A';
  }
}

int main(int argc, char *argv[])
{
  sleep(20);
  printf("About to allocate space\n");
  allocate_space();
  sleep(20);
  printf("About to use space\n");
  use_space();
  sleep(1000);
}

