#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int producer_index = 0;
int consumer_index = 0;
int num_items = 0;
int buffer[BUFFER_SIZE];

int counter = 0;

// function for producer threads
void *producer_function(void *arg)
{
    // make this function thread safe and efficient using condition variables!
    while (1) {
        buffer[producer_index++] = counter++;
        producer_index %= BUFFER_SIZE;
        num_items++;
    }
  
    return NULL;
}

// function for producer threads
void *consumer_function(void *arg)
{
    char *name = (char *)arg;

    // make this function thread safe and efficient using condition variables!
    while (1) {
        int x = buffer[consumer_index++];
        consumer_index %= BUFFER_SIZE;
        num_items--;
        printf("%s consumed %d\n", name, x);
    }

      return NULL;
}
                                                                             
int main(int argc, char *argv[])
{                    
    pthread_t producer_1, producer_2;
    pthread_t consumer_1, consumer_2;

    // create four threads: two producers, two consumers
    pthread_create(&producer_1, NULL, producer_function, "Producer 1");
    pthread_create(&producer_2, NULL, producer_function, "Producer 2");
    pthread_create(&consumer_1, NULL, consumer_function, "Consumer 1");
    pthread_create(&consumer_2, NULL, consumer_function, "Consumer 2");

    // wait for everyone to finish
    pthread_exit(NULL);
    return 0;
}
