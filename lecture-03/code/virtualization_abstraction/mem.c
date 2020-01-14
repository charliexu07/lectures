#include "common.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int value;

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: mem <value>\n");
        exit(1);
    }

    int* p; // memory for pointer is on "stack"
    p = &value;
    assert(p != NULL);

    printf("(pid:%d) addr of p: %p\n", (int)getpid(), &p);
    printf("(pid:%d) addr in p: %p\n", (int)getpid(), p);
    *p = atoi(argv[1]);

    while (1) {
        spin(1);
        *p = *p + 1;
        printf("(pid:%d) value of p: %d\n", getpid(), *p);
    }

    return 0;
}
